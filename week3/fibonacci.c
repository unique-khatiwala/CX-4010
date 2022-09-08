#include <stdio.h>

long count = 2, prev = 0,curr = 1;

void fib(long length);

void main(){
  /*
  long fib_length = 0;
  prlongf("Enter length of fibonacci series you want: \n");
  scanf("%d",&fib_length);
  */
  for(long i = 0; i < 9999; i++){
    count = 2;
    prev = 0;
    curr = 1;
    fib(i);
    printf("The %d position fibonacci number is %d\n",i,curr);
  }

}

void fib(long length){
  if(count < length){
    long temp = curr + prev;
    prev = curr;
    curr = temp;
    count++;
    fib(length);
  }
}
