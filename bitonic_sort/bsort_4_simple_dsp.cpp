#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
void print_array(int* ary, int len);
void shift_array(char flag , char offset , int len , int* ary , int* ary_out);

void pickup_array12(int len , int* ary_in , int* ary_out1 , int* ary_out2);
void pickup_array14(int len , int* ary_in , int* ary_out1 , int* ary_out2);

void merge_array12(int len , int* ary_out , int* ary_in1 , int* ary_in2);
void merge_array14(int len , int* ary_out , int* ary_in1 , int* ary_in2);

void cmp_array(int len , int* ary_in1 , int* ary_in2);

int main()
{
  int i; //roop counter
  int j;
  int k;
  int l_number =0;

  //srand(1000);
  srand((unsigned) time(NULL));

  int len = 4; //array length

  int ary[len] = {0};
  int ary_0[len] = {0};
  int ary_L1[len] = {0};
  int ary_R1[len] = {0};
  int ary_inv[len] = {0};
  int ary_cmp[len] = {0};
  int ary_cmp_inv[len] = {0};
  int *ary_p = &ary[0];

  int ary_half1[len] = {0};
  int ary_half2[len] = {0};
  int ary_L[len] = {0};
  int ary_H[len] = {0};

  for(int i = 0; i < len; i++) {
      ary[i] = rand()%1000;
  }

  //////////////bitonic_sort///////////////////
  /////////////////layer 1///////////////////
  ////////////////for dsp//////////////////
  pickup_array12(len , &ary[0] , &ary_half1[0] , &ary_half2[0]);
  printf("layer%2d : ",l_number);
  l_number++;
  print_array(ary_p , len);
  print_array(&ary_half1[0] , len);
  print_array(&ary_half2[0] , len);

  cmp_array(len , &ary_half1[0] , &ary_half2[0]);
  print_array(&ary_half1[0] , len);
  print_array(&ary_half2[0] , len);

  merge_array12(len , &ary[0] , &ary_half1[0] , &ary_half2[0]);

  /////////////////layer 2///////////////////
  ////////////////for dsp//////////////////
  pickup_array14(len , &ary[0] , &ary_half1[0] , &ary_half2[0]);
  printf("layer%2d : ",l_number);
  l_number++;
  print_array(ary_p , len);
  print_array(&ary_half1[0] , len);
  print_array(&ary_half2[0] , len);

  cmp_array(len , &ary_half1[0] , &ary_half2[0]);
  print_array(&ary_half1[0] , len);
  print_array(&ary_half2[0] , len);

  merge_array14(len , &ary[0] , &ary_half1[0] , &ary_half2[0]);

  /////////////////layer 3///////////////////
  ////////////////for dsp//////////////////
  pickup_array12(len , &ary[0] , &ary_half1[0] , &ary_half2[0]);
  printf("layer%2d : ",l_number);
  l_number++;
  print_array(ary_p , len);
  print_array(&ary_half1[0] , len);
  print_array(&ary_half2[0] , len);

  cmp_array(len , &ary_half1[0] , &ary_half2[0]);
  print_array(&ary_half1[0] , len);
  print_array(&ary_half2[0] , len);

  merge_array12(len , &ary[0] , &ary_half1[0] , &ary_half2[0]);



  printf("layer%2d : ",l_number);
  l_number++;
  print_array(ary_p , len);

  return 0;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int* ary, int len)
{
    for(int i = 0; i < len; i++ ){
        printf( "%3d ", ary[i] );
    }
    printf("\n");
}

void shift_array(char flag , char offset , int len , int* ary , int* ary_out)
{
  if (flag == -1){
    for(int i = 0; i < (len-offset); i++ ){
      ary_out[i] = ary[i+offset];
    }
  }else if (flag == 1){
    for(int i = 0; i < (len-offset); i++){
      ary_out[i+offset] = ary[i];
    }
  }else{}
}

void cmp_array(int len , int* ary_in1 , int* ary_in2)
{
  for(int i = 0; i < (len/2); i++)
  {
    if(ary_in1[i] > ary_in2[i]){
      swap(&ary_in1[i] , &ary_in2[i]);
    }else{}
  }
}

void pickup_array12(int len , int* ary_in , int* ary_out1 , int* ary_out2)
{
  int j = 0;
  for(int i = 0; i < len; i++)
  {
    ary_out1[j] = ary_in[i];
    i++;
    ary_out2[j] = ary_in[i];
    j++;
  }
}

void merge_array12(int len , int* ary_out , int* ary_in1 , int* ary_in2)
{
  int j = 0;
  for(int i = 0; i < len; i++)
  {
    ary_out[i] = ary_in1[j];
    i++;
    ary_out[i] = ary_in2[j];
    j++;
  }
}

void pickup_array14(int len , int* ary_in , int* ary_out1 , int* ary_out2)
{
  int i=0;
  int j=0;
  int k=3;
  int l=0;
  for(i = 0; i < len; i++) {
    ary_out1[l] = ary_in[i];
    ary_out2[l] = ary_in[k];

    if(((j+1)%2)==0){ //2 element finished -> move next 2 element
      i+=2;
      k+=6;
    }
    k--;
    j++;
    l++;
    }
}

void merge_array14(int len , int* ary_out , int* ary_in1 , int* ary_in2)
{
  int i=0;
  int j=0;
  int k=3;
  int l=0;
  for(i = 0; i < len; i++) {
    ary_out[i] = ary_in1[l];
    ary_out[k] = ary_in2[l];

    if(((j+1)%2)==0){ //2 element finished -> move next 2 element
      i+=2;
      k+=6;
    }
    k--;
    j++;
    l++;
    }
}
