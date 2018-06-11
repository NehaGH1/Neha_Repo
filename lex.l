%{
#include<stdio.h>
int v=0,c=0;
%}

%%
is|am|are { printf("%s: is a verb \n",yytext); }
[a-zA-Z]+ {printf("%s: not a verb \n",yytext); }
%%

void main()
{
	char string[20];
	
	printf("\nEnter a string");
	fgets(string,sizeof(string),stdin);
	yy_scan_string(string);
	
	yylex();
}

