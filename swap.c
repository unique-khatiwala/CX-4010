#include <stdio.h>
void swap(int *ptr1, int *ptr2);

int main(){
    int first;
    int second;
    printf("please enter the first number: \n");
    scanf("%d", &first);
    printf("please enter the second number: \n");
    scanf("%d", &second);
    // int first = 5;
    // int second = 10;

    int *ptr1 = &first; //this decleration means ptr1 equals to the address of first
    int *ptr2 = &second;

    
    swap(ptr1, ptr2); //ptr1 and ptr2 equals to the addreass of first and the address of second
    printf("swap the two numbers: \n");
    printf("%d" "\n", first) ;
    printf("%d", second);

}

void swap(int* ptr1, int* ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}