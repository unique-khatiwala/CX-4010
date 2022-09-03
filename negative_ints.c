/*
	program to take a 4-bit binary integer and return negative representations
	treat them as character strings
*/
#include <stdio.h>
#include <math.h>
#define NBITS 4
int PrintBitString(char someint[NBITS]);
int ToDecimal(char bit[NBITS]);

int main()
{

	// initialize
	char myint[NBITS] = "0011";

	printf("original bit string: ");
	PrintBitString(myint);

	// find signmagnitude
	char signmagnitude[NBITS] = "0000";
	if (myint[0] == '0')
		signmagnitude[0] = '1';
	else
		signmagnitude[0] = '0';
	for (int j = 1; j < NBITS; j++)
	{
		signmagnitude[j] = myint[j];
	}

	// find one's represent
	char onerepresent[NBITS] = "0000";
	for (int i = 0; i < NBITS; i++)
	{
		if (myint[i] == '0')
			onerepresent[i] = '1';

		else
			onerepresent[i] = '0';
	}

	// find two's complement
	char tworepresent[NBITS] = "0000";
	int firstone;
	for (int i = NBITS - 1; i > 0; i--)
	{
		if (myint[i] == '1')
		{
			firstone = i;
			break;
		}
	}
	tworepresent[firstone] = '1';
	for (int i = firstone - 1; i >= 0; i--)
	{
		if (myint[i] == '0')
			tworepresent[i] = '1';
		else
			tworepresent[i] = '0';
	}

	printf("sign magnitude of the negative bit string: ");
	PrintBitString(signmagnitude);

	printf("one's represent of the negative bit string: ");
	PrintBitString(onerepresent);

	printf("two's represent of the negative bit string: ");
	PrintBitString(tworepresent);

	int result = 0;
	char mybit[NBITS] = "0011";
	result = ToDecimal(mybit);
	printf("%d", result);

	return 0;
}

int PrintBitString(char someint[NBITS])
{
	for (int j = 0; j < NBITS; j++)
		printf("%c", someint[j]);
	printf("\n");
	return 0;
}

int ToDecimal(char bit[NBITS])
{
	int len = NBITS;
	int result, factor;
	result = 0;
	for (int i = NBITS - 1; i >= 0; i--)
	{
		printf("%d", result);
		if (bit[i] == '1')
			factor = 1;
		else
			factor = 0;
		result += factor * pow(2, (NBITS - 1 - i));
		printf(" +%d*2^ %d=", factor, (NBITS - 1 - i));
		printf("%d\n", result);
	}
	return result;
}
