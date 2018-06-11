%{
#include<stdio.h>
#include<string.h>
int ni=0,pi=0,nf=0,pf=0;

%}

%%
[0-9]+ {pi++;}
[-][0-9]+ {ni++;}
[0-9|'.']+ {pf++;}
[-][0-9|'.']+ {nf++;}
%%

int main()
{
FILE *fp;
char a[100];
fp=fopen("new1.txt","r");
char c;
int j=0;
while((c=fgetc(fp))!=EOF)
{      if(c!=' ')
      { a[j++]=c;
      }
      else
      { 
	yy_scan_string(a);
	yylex();
	strcpy(a,0);
      }
}

printf("%d %d %d %d\n",pi,ni,pf,nf);
fclose(fp);
return 0;
}
