#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
    char ch,prev='a';
    char buffer[15];
    char logicaloperators[]="|&";
    char binaryoperators[] = "+-*/%=";
    FILE *fp;
    int i,j=0;

    fp = fopen("1.txt","r");
    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }

    while((ch = fgetc(fp)) != EOF){
           for(i = 0; i < 6; ++i){
               if(ch == binaryoperators[i])
                   printf("%c is binaryoperator\n", ch);
           }
           //for(i = 0; i < 0; ++i){
               if(ch == '?')
                   printf("%c is ternaryoperator\n", ch);
           //}
           for(i = 0; i < 2; ++i){
               if(ch == logicaloperators[i])
                   printf("%c is logicaloperator\n", ch);
           }
           if(ch=="+" && prev=="+")
            printf("++ is unary operator \n");
           if(ch=="-" && prev=="-")
            printf("-- is unary operator \n");
           prev=ch;
    }

    fclose(fp);

    return 0;
}
