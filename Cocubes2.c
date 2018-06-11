//to print the first non-repeating element in a character array
#include<stdio.h>
#include<string.h>
char str[50];
void func(int n)
{
	int i=1, p=0;
	do
	{
		if(i==p)	i++;
		else if(str[i]==str[p])
		{
			p++;
			i=0;
		}
		else if(str[i]!=str[p] && i==n-1)
		{
			printf("'%c' is the first non-repeating element.\n", str[p]);
			break;
		}
		else if(p==n-1)
		{
			printf("There are no non-repeating elements in the given string.\n");
			break;
		}
		else	i++;
	}while(i<n);
}
void main()
{
	int n;
	printf("Enter the string: ");
	scanf("%s", str);
	n=strlen(str);
	func(n);
}
