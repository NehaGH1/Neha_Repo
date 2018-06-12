#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float m, q, r[4], mag_r, v[4], mag_v, B[4], mag_B, c;

float magnitude(float t[])
{
	double temp, a=1, p[4];
	int i;
	for(i=0;i<4;i++)
	{
		p[i]=pow(t[i], 2);
		a=a*p[i];
	}
	temp=sqrt(a);
	return (float)temp;
}

void display()
{
	
}

void main()
{
	int i;
	char choice='y', ch, flush;
	float t;
	c= 2.99792458 * pow(10, 10);
	do
	{
		printf("Enter the mass and charge of the particle: ");
		scanf("%f %f", &m, &q);
		if(m<0)
		{
			printf("You entered invalid mass, Re-enter.\n");
			continue;
		}
		printf("Enter the starting position and the initial velocity of the charged particle (as a matrix): ");
		r[0]=0;
		v[0]=0;
		for(i=0;i<3;i++)
		{
			scanf("%f", &r[i]);
			//enter exceptions (if any) herein i--;
		}
		for(i=0;i<3;i++)
		{
			scanf("%f", &v[i]);
			//enter exceptions (if any) herein i--;
		}
		printf("Enter the components of the external magnetic field (in the four-vector notation, with the first being the time component) in which the charged particle is placed: ");
		for(i=0;i<4;i++)
		{
			scanf("%f", &B[i]);
			//enter exceptions (if any) herein i--;
		}
		
		mag_r=magnitude(r);
		mag_v=magnitude(v);
		mag_B=magnitude(B);
		
		display();
		printf("Do you want to compute the trajectory of another particle? Y/N\n");
		scanf("%c", &flush);
		scanf("%c", &choice);
	}while(choice=='y' || choice=='Y');
}
