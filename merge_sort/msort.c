#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

static void merge_sort(int* array, size_t size);
static void merge_sort_rec(int* array, size_t begin, size_t end, int* work);
static void print_array(const int* array, size_t size);


int main()
{
  int array[] = {7, 2, 9, 6, 4, 3, 8, 5, 1};

  print_array( array, SIZE_OF_ARRAY(array) );
  merge_sort( array, SIZE_OF_ARRAY(array) );
  print_array( array, SIZE_OF_ARRAY(array) );

  return 0;
}

/////merge sort top/////
void merge_sort(int* array, size_t size)
{
    // 作業用領域を確保
    int* work = malloc( sizeof(int) * size );

    // 配列全体を対象にする
    merge_sort_rec( array, 0, size - 1, work );

    free( work );
}

////merge sort main//////////
void merge_sort_rec(int* array, size_t begin, size_t end, int* work)
{
    // 要素が１つしかなければ終了
    if( begin >= end ){
        return;
    }


    // ２つのデータ列に分割して、それぞれを再帰的に処理
    size_t mid = (begin + end) / 2;
    merge_sort_rec( array, begin, mid, work );
    merge_sort_rec( array, mid + 1, end, work );

    // マージ
    {
        // 前半の要素を作業用配列へ
        for( size_t i = begin; i <= mid; ++i){
            work[i] = array[i];
        }

        // 後半の要素を逆順に作業用配列へ
        for( size_t i = mid + 1, j = end; i <= end; ++i, --j){
            work[i] = array[j];
        }

        // 作業用配列の両端から取り出した要素をマージ
        {
            size_t i = begin;
            size_t j = end;
            for( size_t k = begin; k <= end; ++k) {

                // 昇順にソートするので、小さい方の要素を結果の配列へ移す。
                // == の場合に、前半の側を優先すると安定なソートになる
                if( work[i] <= work[j] ){
                    array[k] = work[i];
                    ++i;
                }
                else{
                    array[k] = work[j];
                    --j;
                }
            }
        }
        print_array( array, 9 );
        printf("begin = %d , end = %d\n",begin,end);
    }
}

void print_array(const int* array, size_t size)
{
    for( size_t i = 0; i < size; ++i ){
        printf( "%d ", array[i] );
    }
    printf( "\n" );
}
