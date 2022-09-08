#include <stdio.h>
int RunningSum(int arg);

int main(void) {
    int num;
    printf("Please enter the number you want the running sum of:\n");
    scanf("%d",&num);
    for (int i =1; i<num; i++){
        printf("The current running sum is %d\n",RunningSum(i));
    }
    printf("The final running sum of %d is %d.\n", num, RunningSum(num));
    printf("Verification:%d\n", num*(num+1)/2);
}

int RunningSum(int arg) {
    if (arg == 0)
        return 0;
    else
       return arg + RunningSum(arg-1); 
}