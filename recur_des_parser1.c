/*S->aSBC | b
B->bB | @
C->dC | @*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char expr[20];
void B();
void C();
int i, f;
void S()
{
	if(expr[i]=='a')
	{
		i++;
		S();
		B();
		C();
	}
	else if (expr[i]=='b') i++;
	else f=1;
}
void B()
{
	if(expr[i]=='b')
	{
		i++;
		B();
	}
}
void C()
{
	if(expr[i]=='d')
	{
		i++;
		C();
	}
}
void main()
{
	i=0, f=0;
	printf("Enter the string: ");
	scanf("%s", expr);
	S();
	if((strlen(expr)==i) && f==0)
		printf("String parsed successfully.\n");
	else
		printf("String rejected.\n");
}
