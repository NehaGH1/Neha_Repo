/* E->TEd
Ed->+TEd | -TEd | @
T->FTd
Td->*FTd | /FTd | @
F->(E) | num */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char expr[20];
void T();
void Ed();
void F();
void Td();
int i, f;
void E()
{
	T();
	Ed();
}
void Ed()
{
	if(expr[i]=='+' || expr[i]=='-')
	{
		i++;
		T();
		Ed();
	}
}
void T()
{
	F();
	Td();
}
void Td()
{
	if(expr[i]=='*' || expr[i]=='/')
	{
		i++;
		F();
		Td();
	}
}
void F()
{
	if(expr[i]=='(')
	{
		i++;
		E();
		if(expr[i]==')')
		{
			i++;
		}
		else f=1;
	}
	else if(expr[i]=='num') i++;
	else f=1;
}
void main()
{
	i=0, f=0;
	printf("Enter the string: ");
	scanf("%s", expr);
	E();
	if((strlen(expr)==i) && f==0)
		printf("String parsed successfully.\n");
	else
		printf("String rejected.\n");
}
