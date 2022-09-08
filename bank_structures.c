// bank program to introduce structures
#include <stdio.h>
#define FUNDLEN 50

typedef struct bank {
	char bankName[FUNDLEN];
	int zipCode;
	int bankID;
} Bank;

typedef struct customer {
	Bank bankInfo;
	int customerID;
	double savingsBalance;
	double checkingBalance;
	double interest;
}Person;

// can use const for these functions because values will not change
double TotalBalance(const Person * acctPtr); // argument is a pointer
double SavingsShare(const Person patron); // argument is a structure
void PrintBankInfo(const Bank bankhere); //argument is a structure
double InterestCalculation(const Person patron);
double InterestCalculationPointer(const Person * patron);

int main(void) 
{
	Bank gtbank = {
		"Georgia Tech Bank",
		30000,
		8810
	};
	
	Person Anna = {
		gtbank,
		12345,
		2593.53,
		842.15,
		0.01
	};

	printf("Anna's customerID is %d.\n",Anna.customerID);
	printf("Anna has a total of $%.2f.\n",TotalBalance(&Anna));
	printf("%.1f percent of her total is in savings.\n",SavingsShare(Anna));
	printf("Her bank's ID is %d.\n",Anna.bankInfo.bankID); 
	printf("The annual expected interest is %.2f.\n", Anna.savingsBalance*Anna.interest);
	PrintBankInfo(Anna.bankInfo);
	InterestCalculation(Anna);
	InterestCalculationPointer(&Anna);
	
}

double TotalBalance(const Person * acctPtr) 
{
	// use -> notation because acct is a pointer; this allows access to the field
	return (acctPtr->savingsBalance + acctPtr->checkingBalance);
}

double SavingsShare(const Person patron) // argument is a structure
{
	return (100.0 * patron.savingsBalance / (patron.savingsBalance+patron.checkingBalance) );
}

void PrintBankInfo(const Bank bankhere) //argument is a structure
{
	printf("Her bank's name is %s.\n",bankhere.bankName);
}

double InterestCalculation(const Person patron) {
	printf("The annual expected interest is %.2f.\n", patron.savingsBalance*patron.interest);
}

double InterestCalculationPointer(const Person * patron) {
	printf("The annual expected interest is %.2f.\n", patron->savingsBalance*patron->interest);
}