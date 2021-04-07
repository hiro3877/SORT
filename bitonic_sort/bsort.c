#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DATA_LEN 18	//要素数は2^nです

#define max( a, b ) ( ( a ) > ( b ) ? ( a ) : ( b ) )
#define min( a, b ) ( ( a ) < ( b ) ? ( a ) : ( b ) )

int main(void) {

	int data[ DATA_LEN ];	//乱数配列
	int step = 0;		//並列計算可能部の繰り返し回数
	int phase = 0;		//並列計算での入れ替え回数（ 以下フェイズ ）
	int phasePrev = -1;	//↑の前回の値 入れ替え処理が終了したかを判断
	long long int cmp;	//入れ替え対象への添字への相対
	long long int skip;	//入れ替え方向振り分け用変数
	int maxPhase;		//並列計算のオーダー

	srand( ( unsigned long )time( NULL ) );

	//乱数配列生成
	for ( long long int i = 0; i < DATA_LEN; i++ )
		data[ i ] = ( rand() % 1000 );

	//生成結果出力
	puts( "Random" );
	for ( long long int i = 0; i < DATA_LEN; i++ )
		printf( "%3d : %3d\n", i, data[ i ] );

	//区画分けしてソートする回数 log_2( n )
	maxPhase = log2l( DATA_LEN );

	while( phase < maxPhase ){
		if ( phasePrev != phase )		//フェイズが変化していた場合
		{
			phasePrev = phase;			//今まで実行していたフェイズを記憶
			step = 0;				//要素入れ替えステップの初期化

			//普通に2^phaseで計算したいけどC言語のpowの指数部には0が入れられない
			//入れ替え対象への添字更新
			cmp = phase > 0 ? ( long long int )powl( 2, phase ) : 1;
			//入れ替え方向振り分け用の値の更新
			skip = phase > 0 ? ( long long int )powl( 2, phase + 1 ) : 2;
		}

		//　!-----------ここから並列計算可---------------!
		for ( long long int i = 0; i < DATA_LEN - cmp; i++ )
		{
			int tmp;	//一時退避変数
			if ( ( ( i / cmp ) % 2 ) == 0 )	//入れ替え済み要素のスキップ
			{
				if ( ( i / skip ) % 2 ) {
					//添字が大きい要素に対して小さい値が集まるように入れ替え
					tmp = min( data[ i ], data[ i + cmp ] );
					data[ i ] = max( data[ i ], data[ i + cmp ] );
					data[ i + cmp ] = tmp;
				}
				else
				{
					//添字が大きい要素に対して大きい値が集まるように入れ替え
					tmp = max( data[i], data[i + cmp] );
					data[ i ] = min( data[i], data[i + cmp] );
					data[ i + cmp ] = tmp;
				}
			}
		}
		//　!-----------ここまで並列計算可---------------!

		if ( step < phase )
		{
			step++;		//入れ替えステップ進行
			cmp /= 2;	//入れ替え対象の変更
		}
		else
		{
			phase++;	//フェイズ移行
		}

	}

	//実行結果出力
	puts( "\nResult" );
	for ( int i = 0; i < DATA_LEN; i++ )
		printf( "%3d : %3d\n", i, data[i] );

}
