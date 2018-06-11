#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<strings.h>
void main()
{
	FILE *fp, *fp2, *fp3;
	int p, i=0, q;
	char filename[100], str[35];   //since max limit of identifier length =31
	printf("Enter the file name from which you have to extract the identifiers and keywords: ");
	scanf("%s", filename);
	fp = fopen(filename,"r");
	if(fp == NULL)
	{
		printf("File doesn't exist.\n");
	}
	fp2 = fopen("new2.txt","r+");
	fp3 = fopen("new3.txt","r+");
	while(q=getc(fp)!=EOF)
	{
	//fputc(q,fp2);
		if(q == '_' || q > 64 && q < 91 || q > 96 && q < 123) 
		{
			i=0;
			str[i]=q;
			p=getc(fp);
			//printf("%c",str[i]);
			while((p == '_' || p > 64 && p < 91 || p > 96 && p < 123 || p > 47 && p < 58) && p != 32 && p!=EOF)
			{
				i++;
				str[i]=p;
				p=getc(fp);
			}
			if((p==32 || p==EOF) && strlen(str)<32)
			{
				for(i=0;i<=strlen(str);i++){ fputc(str[i],fp2); }
				//fputc(11,fp2);
			}
		}
		
	}
	//fp3 = fopen("new3.txt","r+");
	while(p=getc(fp2)!=EOF)
	{
		i=-1;
		while(p!=32 && p!=EOF)
		{
			i++;
			str[i]=q;
			p=getc(fp2);
		}//all 32 keywords
		if(strcmp(str, "auto") || strcmp(str, "break") || strcmp(str, "case") || 
		strcmp(str, "const") || strcmp(str, "char") || strcmp(str, "int") || 
		strcmp(str, "default") || strcmp(str, "do") || strcmp(str, "double") || 
		strcmp(str, "else") || strcmp(str, "enum") || strcmp(str, "extern") || 
		strcmp(str, "float") || strcmp(str, "for") || strcmp(str, "goto") || 
		strcmp(str, "short") || strcmp(str, "continue") || strcmp(str, "long") || 
		strcmp(str, "register") || strcmp(str, "return") || strcmp(str, "if") || 
		strcmp(str, "signed") || strcmp(str, "sizeof") || strcmp(str, "static") || 
		strcmp(str, "struct") || strcmp(str, "switch") || strcmp(str, "typedef") || 
		strcmp(str, "union") || strcmp(str, "unsigned") || strcmp(str, "void") || 
		strcmp(str, "volatile") || strcmp(str, "while"))
		{
			for(i=0;i<=strlen(str);i++){ fputc(str[i],fp3); }
			//fputc(11,fp3);
		}
	}
	if(fp2 == NULL)
		printf("Said file doesn't contain any identifiers.\n");
	else if(fp3 == NULL)
		printf("Said file doesn't contain any keywords.\n");
	else
		printf("Segregation successful.\n");
	fclose(fp);
	fclose(fp2);
	fclose(fp3);
}

