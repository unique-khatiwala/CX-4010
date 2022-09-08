#include <stdio.h>

int sum(int);

int main(){
    int num;
    printf("please enter a number: \n");
    scanf("%d", &num);
    int ans = sum(num);
    printf("%d \n", ans);

    printf("verify 1: \n");
    int sum1 = 0;
    for(int i = 1; i <= num; i++){
        sum1 = sum1 + i;
        printf("%d \n", sum1);
    }

    printf("verify 2: \n");
    int sum2 = 0;
    sum2 = num*(num + 1) / 2;
    printf("%d \n", sum2);


}

int sum(int n){
    if(n == 1){
        return 1;
    }
    return sum(n-1)+n;
}