#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void S();
void Sd();
void A();
void Ad();
int i, f;
char expr[20];
void S()
{
	if(expr[i]=='b')
	{
		i++;
		Sd();
	}
	else
	{
		A();
		if(expr[i]=='a')
		{
			i++;
			Sd();
		}
		else	f=1;
	}
}
void Sd()
{
	if(expr[i]=='a')
	{
		i++;
		Sd();
	}
}
void A()
{
	if(expr[i]=='b')
	{
		i++;
		Sd();
		if(expr[i]=='b')
		{
			i++;
			Ad();
		}
		else	f=1;
	}
	else if(expr[i]=='c')
	{
		i++;
		Ad();
	}
	else	f=1;
}
void Ad()
{
	if(expr[i]=='b')
	{
		i++;
		Ad();
	}
	else if(expr[i]=='a')
	{
		i++;
		Sd();
		if(expr[i]=='b')
		{
			i++;
			Ad();
		}
		//else	f=1;
	}
}
void main()
{
	i=0, f=0;
	printf("Enter the string: ");
	scanf("%s", expr);
	S();
	if(strlen(expr)==i && f==0)
	{
		printf("String parsed successfully.\n");
	}
	else
		printf("String rejected.\n");
}
