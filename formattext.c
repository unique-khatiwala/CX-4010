/*
	formatting: C will format your variables however you tell it
*/
#include <stdio.h>
#include <limits.h> // includes some system constants like INT_MAX and INT_MIN

int main()
{
	printf("maximum integer = %d, minimum integer = %d\n\n",INT_MAX,INT_MIN);

	int myint = 41;
	float myfloat = 16.23591;
	double mydouble = 39.172438103536;
	char mychar = 'n';
	unsigned myunsigned = 125;

	printf("printing all as int:\n");
	printf("myint = %d, myfloat = %d, mydouble = %d, mychar = %d\n",myint,(int)myfloat,(int)mydouble,mychar);
	
	printf("printing all as char:\n");
	printf("myint = %c, myfloat = %c, mydouble = %c, mychar = %c\n",myint,(int)myfloat,(int)mydouble,mychar);
	
	printf("printing all as hex:\n");
	printf("myint = %X, myfloat = %X, mydouble = %X, mychar = %X\n",myint,(int)myfloat,(int)mydouble,mychar);
	
	printf("printing all with floating-point notation:\n");
	printf("myint = %f, myfloat = %f, mydouble = %f, mychar = %f\n",(float)myint,myfloat,mydouble,(float)mychar);

	printf("printing all with floating-point e-notation:\n");
	printf("myint = %e, myfloat = %e, mydouble = %e, mychar = %e\n",(double)myint,myfloat,mydouble,(double)mychar);
	
	printf("printing all with floating-point notation, decimals specified:\n");
	printf("myint = %.10f, myfloat = %.10f, mydouble = %.10f, mychar = %.10f\n",(float)myint,myfloat,mydouble,(float)mychar);

	printf("what does this one do?\n");
	printf("myint = %9.4f, myfloat = %9.4f, mydouble = %9.4f, mychar = %9.4f\n",(double)myint,myfloat,mydouble,(double)mychar);

	return 0;
}