/* S->BCDEF
B->bBC | c
C->cC | dD
D->dD | eF
E->eF | g
F->g | h */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char expr[20];
void B();
void C();
void D();
void E();
void F();
int i, f;
void S()
{
	B();
	C();
	D();
	E();
	F();
}
void B()
{
	if(expr[i]=='b')
	{
		i++;
		B();
		C();
	}
	else if(expr[i]=='c')
	{
		i++;
	}
	else f=1;
}
void C()
{
	if(expr[i]=='c')
	{
		i++;
		C();
	}
	else if(expr[i]=='d')
	{
		i++;
		D();
	}
	else f=1;
}
void D()
{
	if(expr[i]=='d')
	{
		i++;
		D();
	}
	else if(expr[i]=='e')
	{
		i++;
		E();
	}
	else f==1;
}
void E()
{
	if(expr[i]=='e')
	{
		i++;
		F();
	}
	else if(expr[i]=='g')
	{
		i++;
	}
	else f=1;
}
void F()
{
	if(expr[i]=='g')
	{
		i++;
	}
	else if(expr[i]=='h') i++;
	else f=1;
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
