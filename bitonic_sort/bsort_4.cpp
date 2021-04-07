#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
void print_array(int* ary, int len);

int main()
{
  int i; //roop counter
  int j; //Acending or Descending , determine flag
  //srand(1000);
  srand((unsigned) time(NULL));
  int len = 4; //array length
  int ary[len];
  int *ary_p = &ary[0];
  for(int i = 0; i < len; i++) {
      ary[i] = rand()%1000;
  }

  print_array(ary_p , len);

  //////////////bitonic_sort///////////////////

  /////////////////layer 1///////////////////
  /////compare (0,1) (2,3) ... , even->Acending , odd->Descending/////////
  j=0; //j initialize
  for(i = 0; i < len; i+=2) {
    if(j%2==0){
      if(ary[i] > ary[i+1]){
        swap(&ary[i],&ary[i+1]);
      }else{} //do nothing
    }else{ //if(j%2==1)
      if(ary[i] < ary[i+1]){
        swap(&ary[i],&ary[i+1]);
      }else{} //do nothing
    }
  j++;
  }

  print_array(ary_p , len);

  /////////////////layer 2///////////////////
  /////compare (0,2) (1,3) ... , 2 element->Acending , next 2 element->Descending .../////////
  j=0; //j initialize
  for(i = 0; i < len; i++) {
    if((j%4)<2){
      if(ary[i] > ary[i+2]){
        swap(&ary[i],&ary[i+2]);
      }else{} //do nothing
    }else{ //if((j%4)>2)
      if(ary[i] < ary[i+2]){
        swap(&ary[i],&ary[i+2]);
      }else{} //do nothing
    }
  if(((j+1)%2)==0){ //2 element finished -> move next 2 element
    i+=2;
  }
  j++;
  }

  print_array(ary_p , len);

  /////////////////layer 3///////////////////
  /////compare (0,1) (2,3) ... , even->Acending , odd->Ascending/////////
  for(i = 0; i < len; i+=2) {
    if(ary[i] > ary[i+1]){
      swap(&ary[i],&ary[i+1]);
    }else{} //do nothing
  }

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
