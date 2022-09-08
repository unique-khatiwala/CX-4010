#include <stdio.h>

int fib(int n);

void main(){
  for(int i = 0;i < 100; i++ ) {
printf("index %d, fibonacci %d\n",i,fib(i));
}
}

int fib(int n){
  if ((n==0)||(n==1)){
    return 1;
  } else {
    return fib(n-1) + fib(n-2);
  }
}
