/*
	working with bit strings as character arrays
*/
#include <stdio.h>
#define NBITS 4
void PrintBitString(char* someint);
void BitwiseAND(char* someint1, char* someint2);
void BitwiseOR(char* someint1, char* someint2);
void BitwiseXOR(char* someint1, char* someint2);

int main() 
{
	// initialize three bit strings as character arrays
	char myint1[NBITS] = "0101";
	char myint2[NBITS] = "1001";
	char myint3[NBITS] = "0000";

	printf("bit string 1: ");
	PrintBitString(myint1);
	
	printf("bit string 2: ");
	PrintBitString(myint2);

	printf("bit string 3: ");
	PrintBitString(myint3);

	BitwiseAND(myint1, myint2);
	BitwiseAND(myint1, myint3);
	BitwiseAND(myint2, myint3);

	printf("\n");

	BitwiseOR(myint1, myint2);
	BitwiseOR(myint1, myint3);
	BitwiseOR(myint2, myint3);

	printf("\n");

	BitwiseXOR(myint1, myint2);
	BitwiseXOR(myint1, myint3);
	BitwiseXOR(myint2, myint3);

	return 0;
}

void PrintBitString(char* someint)
{
	for (int j=0; j<NBITS; j++)
		printf("%c",someint[j]);
	printf("\n");
}

// void bitwiseAND(char* someint1, char* someint2){
// 	int j = 0;
// 	char myintAND[NBITS];
// 	for (int i = 0; i < NBITS; i++){
// 		if(someint1[i] == 1 && someint2[j++] == 1){
// 			myintAND[i] = "1";
// 		} else {
// 			myintAND[i] = "0";
// 		}
// 		printf("%c", myintAND[i]);
// 	}
// 	printf("\n");
// }

void BitwiseAND(char* someint1, char* someint2){
	int j = 0;
	for (int i = 0; i < NBITS; i++){
		if(someint1[i] == '1' && someint2[j] == '1'){
			printf("%d",1);
		} else {
			printf("%d",0);
		}
		j++;
	}
	printf("\n");
}

void BitwiseOR(char* someint1, char* someint2){
	int j = 0;
	for (int i = 0; i < NBITS; i++){
		if(someint1[i] == '1' || someint2[j] == '1'){
			printf("%d",1);
		} else {
			printf("%d",0);
		}
		j++;
	}
	printf("\n");
}

void BitwiseXOR(char* someint1, char* someint2){
	int j = 0;
	for (int i = 0; i < NBITS; i++){
		if(someint1[i] == someint2[j]){
			printf("%d",0);
		} else {
			printf("%d",1);
		}
		j++;
	}
	printf("\n");
}

