#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
void print_array(int* ary, int len);

int main()
{
  int i; //roop counter
  int j;
  int k;
  int l_number =0;
  //srand(1000);
  srand((unsigned) time(NULL));
  int len = 16; //array length
  int ary[len];
  int *ary_p = &ary[0];
  for(int i = 0; i < len; i++) {
      ary[i] = rand()%1000;
  }

  printf("layer%2d ",l_number);
  print_array(ary_p , len);

  //////////////bitonic_sort///////////////////

  /////////////////layer 1///////////////////
  /////compare (0,1) (2,3) ... , Acending/////////
  for(i = 0; i < len; i+=2) {
    if(ary[i] > ary[i+1]){
      swap(&ary[i],&ary[i+1]);
    }else{} //do nothing
  }

  l_number++;
  printf("layer%2d ",l_number);
  print_array(ary_p , len);

  /////////////////layer 2///////////////////
  /////compare (0,3) (1,2) ... , 2 element->Acending , next 2 element->Acending .../////////
  j=0; //j initialize
  k=3; //j initialize
  for(i = 0; i < len; i++) {
    if(ary[i] > ary[k]){
      swap(&ary[i],&ary[k]);
    }else{} //do nothing

    if(((j+1)%2)==0){ //2 element finished -> move next 2 element
      i+=2;
      k+=6;
    }
    k--;
    j++;
    }

  l_number++;
  printf("layer%2d ",l_number);
  print_array(ary_p , len);

  /////////////////layer 3///////////////////
  /////compare (0,1) (2,3) ... , Acending/////////
  for(i = 0; i < len; i+=2) {
    if(ary[i] > ary[i+1]){
      swap(&ary[i],&ary[i+1]);
    }else{} //do nothing
  }

  l_number++;
  printf("layer%2d ",l_number);
  print_array(ary_p , len);

  /////////////////layer 4///////////////////
  /////compare (0,7) (1,6) ... , 4 element->Acending , next 4 element->Acending .../////////
  j=0; //j initialize
  k=7; //j initialize
  for(i = 0; i < len; i++) {
    if(ary[i] > ary[k]){
      swap(&ary[i],&ary[k]);
    }else{} //do nothing

    if(((j+1)%4)==0){ //4 element finished -> move next 4 element
      i+=4;
      k+=12;
    }
    k--;
    j++;
    }

  l_number++;
  printf("layer%2d ",l_number);
  print_array(ary_p , len);

  /////////////////layer 5///////////////////
  /////compare (0,2) (1,3) ... , even->Acending , odd->Ascending/////////
  j=0; //j initialize
  for(i = 0; i < len; i++) {
    if(ary[i] > ary[i+2]){
      swap(&ary[i],&ary[i+2]);
    }else{} //do nothing

  if(((j+1)%2)==0){ //2 element finished -> move next 2 element
    i+=2;
  }
  j++;
  }

  l_number++;
  printf("layer%2d ",l_number);
  print_array(ary_p , len);

  /////////////////layer 6///////////////////
  /////compare (0,1) (2,3) ... , Acending/////////
  for(i = 0; i < len; i+=2) {
    if(ary[i] > ary[i+1]){
      swap(&ary[i],&ary[i+1]);
    }else{} //do nothing
  }

  l_number++;
  printf("layer%2d ",l_number);
  print_array(ary_p , len);

  /////////////////layer 7///////////////////
  /////compare (0,15) (1,14) ... , 8 element->Acending , next 8 element->Acending .../////////
  j=0; //j initialize
  k=15; //j initialize
  for(i = 0; i < len; i++) {
    if(ary[i] > ary[k]){
      swap(&ary[i],&ary[k]);
    }else{} //do nothing

    if(((j+1)%8)==0){ //8 element finished -> move next 8 element
      i+=8;
      k+=24;
    }
    k--;
    j++;
    }

  l_number++;
  printf("layer%2d ",l_number);
  print_array(ary_p , len);

  /////////////////layer 8///////////////////
  /////compare (0,4) (1,5) ... , even->Acending , odd->Ascending/////////
  j=0; //j initialize
  for(i = 0; i < len; i++) {
    if(ary[i] > ary[i+4]){
      swap(&ary[i],&ary[i+4]);
    }else{} //do nothing

  if(((j+1)%4)==0){ //4 element finished -> move next 4 element
    i+=4;
  }
  j++;
  }

  l_number++;
  printf("layer%2d ",l_number);
  print_array(ary_p , len);

  /////////////////layer 9///////////////////
  /////compare (0,2) (1,3) ... , even->Acending , odd->Ascending/////////
  j=0; //j initialize
  for(i = 0; i < len; i++) {
    if(ary[i] > ary[i+2]){
      swap(&ary[i],&ary[i+2]);
    }else{} //do nothing

  if(((j+1)%2)==0){ //2 element finished -> move next 2 element
    i+=2;
  }
  j++;
  }

  l_number++;
  printf("layer%2d ",l_number);
  print_array(ary_p , len);

  /////////////////layer 10///////////////////
  /////compare (0,1) (2,3) ... , Acending/////////
  for(i = 0; i < len; i+=2) {
    if(ary[i] > ary[i+1]){
      swap(&ary[i],&ary[i+1]);
    }else{} //do nothing
  }

  l_number++;
  printf("layer%2d ",l_number);
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
        printf( "%d ", ary[i] );
    }
    printf("\n");
}
