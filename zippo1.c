// fun with arrays and pointers
#include <stdio.h>
int main(void)
{
	int zippo[4][3] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};

	printf("   zippo = %p,    zippo + 1 = %p\n",
		   zippo, zippo + 1);
	printf("   zippo = %p,    zippo[0] = %p\n",
		   zippo, zippo[0]);
	printf("   zippo = %p,    *zippo = %p\n",
		   zippo, *zippo);
	printf("zippo[0] = %p, zippo[0] + 1 = %p\n",
		   zippo[0], zippo[0] + 1);
	printf("  *zippo = %p,   *zippo + 1 = %p\n",
		   *zippo, *zippo + 1);
	printf("zippo[0][0] = %d\n", zippo[0][0]);
	printf("  *zippo[0] = %d\n", *zippo[0]);
	printf("    **zippo = %d\n", **zippo);
	printf("      zippo[2][1] = %d\n", zippo[2][1]);
	printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1));
}
/*
1. zippo & zippo+1
	Here the type specifier "%p" asks for a pointer value, so both zippo and zippo + 1 will be pointer values
	since zippo points to the first element in the array, zippo + 1 will points to the second,
	since the inner array has size of 2, zippo + 1 should be 4 unit larger than zippo
2. zippo & zippo[0]
	Type specifier "%p" asks for a pointer value, pointer zippo points to zippo[0],
	then pointer zippo[0] will points to the zippo[0][0].
	Since the pointer pointing to an array is by defaul pointing to the index 0,
	zippo and zippo[0] should be the same
3. zippo[0] and zippo[0] + 1
	As said, zippo[0] points to zippo[0][0], then zippo[0]+1 points to zippo[0][1],
	which in value will be 4 unit larger than zippo[0]
4. *zippo & *zippo+1 are similar to 3.

5. zippo[0][0] == 2

6. *zippo[0] == zippo[0][0] == 2

7. **zippo == *zippo[0] == zippo[0][0] == 2

8. *(*(zippo + 2) + 1) == zippo[2][1] == 3

*/
