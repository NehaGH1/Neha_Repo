#include <stdio.h>

int main()
{
  FILE *fr, *t;
  char c;
  int i=0;
  fr = fopen("prog.txt", "r");
  t = fopen("res.txt", "w");
  while( c != EOF)
  {
    c = (char) fgetc(fr); /* read from file*/
    //printf("%c",c); /*  display on screen*/
    switch(c){
    case '+':if( (fgetc(fr))=='+' ){
                fprintf(t," Unary");
                }
                else{
                fprintf(t," Binary");
                }
                break;
    case '-':if( (fgetc(fr))=='-' ){
                fprintf(t," Unary");
                }
                else{
                fprintf(t," Binary");
                }
                break;
    case '*':fprintf(t," Binary");
                break;
    case '/':fprintf(t," Binary");
                break;
    case '<':fprintf(t," Binary");
                break;
    case '>':fprintf(t," Binary");
                break;
    case '&':fprintf(t," Unary");
                break;
    case '~':fprintf(t," Unary");
                break;
    case '!':fprintf(t," Unary");
                break;
    case '=':if( (fgetc(fr))=='=' ) fprintf(t,"== Unary");
                break;
    case '?':while(c !=';'){
    			c = (char) fgetc(fr);
    			if(c==':'){
    			fprintf(t, " Ternary");
    			break;
    			}
    		}
    }
    
  }
  fclose(fr);
  fclose(t);
  return 0;
}
