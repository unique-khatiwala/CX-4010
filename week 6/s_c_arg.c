#include <stdio.h>
#include <stdlib.h> // needed for function atoi()


int main(int argc, char *argv[])
{
	int i,nreps;
	i = atoi(argv[2]);
	
	if(argc == 3 && *argv[1] == 's')
		printf("The squared value is %d",argc);
	else if(argc == 3 && *argv[1] == 'c')
		printf("The cubed value is %d",(i*i*i));
	else
	{
		printf("Error\n");
	}
	return 0;

}
