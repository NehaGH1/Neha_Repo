//S->aS | b

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i, f;
char expr[50];
void S()
{
	if(expr[i]=='a')
	{
		i++;
		S();
	}
	else if(expr[i]=='b') i++;
	else f=1;
}
void main()
{
	i=0, f=0;
	printf("Input the string: \n");
	scanf("%s", expr);
	S();
	if((strlen(expr)==i) && f==0)
		printf("String parsed successfully.\n");
	else printf("String rejected.\n");
}
