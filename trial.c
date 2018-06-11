#include <stdio.h>
 
/* function declaration */
void swap(float *x, float *y, int p[], int q[]);
 
int main () {

   /* local variable definition */
   float a = 100;
   float b = 200;
   int j, c1[4]={1,4,6,7}, c2[4]={2,56,8,1};
   
   printf("Before swap, value of a : %f\n", a );
   printf("Before swap, value of b : %f\n", b );
 
   /* calling a function to swap the values.
      * &a indicates pointer to a ie. address of variable a and 
      * &b indicates pointer to b ie. address of variable b.
   */
   swap(&a, &b, c1, c2);
 
   printf("After swap, value of a : %f\n", a );
   printf("After swap, value of b : %f\n", b );
 
   return 0;
}

/* function definition to swap the values */
void swap(float *x, float *y, int p[], int q[]) {

   int i, j, n=0, c[2][4];
   float temp;
   temp = *x;    /* save the value at address x */
   *x = *y;      /* put y into x */
   *y = temp;    /* put temp into y */
   
   for(i=0;i<2;i++)
   {
   	for(j=0;j<4;j++)
   	{
   		if(n==0)
		{
			c[i][j]=p[j];
		}
		else
		{
			c[i][j]=q[j];
		}
   	}
   	n=1;
   }
   for(i=0;i<2;i++)
   {
   	for(j=0;j<4;j++)
   	{
   		printf("%d\t", c[i][j]);
   	}
   	printf("\n");
   }
}
