// fun with arrays and pointers
#include <stdio.h>
int main(void)
{
	int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
	/* To declare a pointer variable that can point to a two-dimensional array
		like zippo, we must use a pointer that points to an array of two ints,
		not to a single int.
		We instead use int (*pz)[2]:
		pz is a pointer to an array of 2-ints.
		Parentheses are needed because [] has a higher precedence than *
	*/

	int(*pz)[2];
	pz = zippo; // don't forget to assign the pointer pz a value!

	/* In general you can represent individual elements by using array notation
		or pointer notation with either an array name or a pointer
			zippo[m][n] == *(*(zippo + m) + n)
			pz[m][n] 	== *(*(   pz + m) + n)

	*/

	printf("   pz = %p,    pz + 1 = %p\n", pz, pz + 1);
	printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
	printf("  *pz = %p,   *pz + 1 = %p\n", *pz, *pz + 1);
	printf("pz[0][0] = %d\n", pz[0][0]);
	printf("  *pz[0] = %d\n", *pz[0]);
	printf("    **pz = %d\n", **pz);
	printf("      pz[2][1] = %d\n", pz[2][1]);
	printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
}

/*
1. pz + 1 will be 4 larger than pz, which is space for a int[2] array

2. pz[0]+1 will be 4 larger than pz[0], which is space for an int

3. same as 2.

4. pz[0][0] should be 2

5. *pz[0] should be the same with pz[0][0]

6. **pz should be same with pz[0][0], and *pz[0]

7. pz[2][1] should be 3

8. *(*(pz + 2) + 1) should equal to pz[2][1] == 3

*/