#include <stdlib.h>
#include <stdio.h>
void main()
{
	FILE *fp, *fp2;
	int p;
	char filename[100];
	printf("enter the file name from which you have to remove the extra blank spaces: ");
	scanf("%s",filename);
	fp = fopen(filename,"r");
	if (fp == NULL)
	{
		printf("File doesn't exist");
	}
	fp2 = fopen("new1.txt","w");
	while((p=getc(fp))!=EOF)
	{
		if (p==32) 
		{
			while((p=getc(fp))==32)
			{

			}
			fputc(p,fp2);
		}
		else
			fputc(p,fp2);
	}
	fclose(fp);
	fclose(fp2);
}
