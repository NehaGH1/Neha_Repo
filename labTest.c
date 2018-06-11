#include<stdio.h>
#include<string.h>
char str[100];
int f=0,i=0;
void S();
void A();
void main()
{
	printf("enter the string\n");
	scanf("%s",str);
	S();

	if((strlen(str)==i) && (f==0))
	{
		printf("String accepted\n" );
		
	}
	else
	{
		printf("not accepted\n");
	}
}
void S()
{
	
	
	if(str[i]=='c')
	{
	A();
	}
	if(str[i]=='a')
	{
	i++;
	
	}
	else if(str[i]=='b')
	{
	A();
	}
	else
	{
	f=1;
	}
}
void A()
{
	
	if(str[i]=='b')
	{ 
		i++;
		S();
	}
	else if(str[i]=='c')
	{
		i++;
		
	}

	else
	{
	f=1;
	}	}
											
