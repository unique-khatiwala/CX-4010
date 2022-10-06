// program to add a word to a file
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	
	FILE *fp; 
	fp = fopen(argv[1],"w");	
	int a = 8;
	int b = 2;
	// fprintf(fp,"writing out info to the file: %d + %d = %d\n",a,b,a+b);
	fprintf(fp,"%d\t%d\n%d\n",a,b,a+b);
	fprintf(fp,"%d\n%d\t",a*b,a/b);
	fclose(fp);

	fp = fopen(argv[1],"r");
	int c, d, e;
	//fscanf(fp,"%d\t%d\n",&c,&d);
	//fscanf(fp,"%d",&e);

	fscanf(fp,"%d %d",&c,&d);
	fscanf(fp,"%d",&e);

//	fscanf(fp,"%d%d%d",&c,&d,&e);
	fclose(fp);
	
	printf("c=%d, d=%d, e=%d\n",c,d,e);
}
