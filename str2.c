#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
void main()
{
	int i, p=0, f, q=1, t=0;
	char s='y', flush;
	char *ch;
	do{
		printf("Enter string length: ");
		scanf("%d", &n);
		if(n != 7) q=0;
		ch = (char *)malloc(n*sizeof(char ));
		for(i=0;i<n;i++)
		{
			f=0;
			printf("Enter symbol: ");
			scanf("%c", &flush);
			scanf("%c", &ch[i]);
			if(ch[i] != 'a' && ch[i] != 'b') p=-1;
		}
		if(ch[n-4] == 'b') t=1;
		if(t==1 && q==1 && p!=-1)
		{
			printf("String is accepted.");
		}
		else
		{
			printf("String is not accepted.");
		}
		printf("Do you want to check another string? Yes/No\n");
		scanf("%c", &flush);
		scanf("%c", &s);
	}while(s=='y' || s=='Y');
}
