//code to compute the trajectory of a charged particle in a constant external magnetic field
/*
Input mass (m), charge (q), starting position (r) and initial velocity (v) {in units of 'c'- the speed of light} of the particle, the external magnetic field (B) as a vector (matrix- we are considering 3-dimensional space);
Output equation of motion (trajectory/path) of the particle;
Considering only perpendicular component of motion of the particle, as the parallel component is unaffected by B;
Since a magnetic field B does no work, so the kinetic energy and speed of a charged particle in a magnetic field remain constant;
 so, the particle must have some initial velocity, as B can only change the direction and not the magnitude of the velocity of the particle
For manipulating the scalar and vector potentials (V and A) without affecting the electric and magnetic fields (E and B), we exploit gauge freedom, using the Lorenz Gauge Transformation
[initially try by taking v.z=0, and B.x=B.y=0]
To get the trajectory just plot the different positions of the particle at different times via a line graph
We take all values in the CGS system of units
Reduce the plot.csv file into plot2.csv file using reduce.awk file and the command: sed -f 'reduce.awk' plot.csv > plot2.csv

Reuired additions: Add SI to CGS conversiosfor every value(v,r,m,q); Add options for selecting whether particle is a proton,etc as well
Use "gcc path_in_const_B.c -lm" to compile; since math.h library functions like pow, sqrt, etc need the code to be linked with -lm during compilation
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Vector{
	double x, y, z;
}r, v, B, a;

double m, q, b, E, mag_r, mag_v, mag_B, mag_a, c, w, f, L_fac, time=0, t_int;	//declare P for power and ang=0 for the angle
FILE *fp;

double magnitude(struct Vector tp)
{
	double p;
	p= pow(tp.x, 2) + pow(tp.y, 2) + pow(tp.z, 2);
	return sqrt(p); 
}

/*void v_angle_B()
{
	double p;
	p= ((v.x*B.x) + (v.y*B.y) + (v.z*B.z))/(mag_v*mag_B);
	ang= acos(p);
	if(ang!=ang)
	{
		ang=0;
	}
}*/

void compute()
{
	w= (q*mag_B)/(m*c);	//Angular Velocity of the rotation=q*B/m*c
	f= w/(2*3.14159265358); //Characteristic (Cyclotron) Frequency=w/2*pi
	if(f<0)	f=-f;	//managing the sign convention for the charges
	t_int= 1/(f*10000);	//Total time period (T)=1/f; and time intervals between each position change=T/100
	printf("Time interval= %lf\nf=%lf\n\tTime\t\t Position\t Velocity\t\tAcceleration\n", t_int, f);
	
	while(time<=10*(1/f))	//DOUBT: would t_int vary constantly? if not how to accomodate for varying B?
	{
		b=mag_v/c;	//Velocity of the particle in units of speed of light
		L_fac=1/(sqrt(1-pow(b,2)));	//Lorentz Factor=1/sqrt(1-(v^2)/(c^2))
		//v_angle_B();
		if(L_fac>=(3/4) && L_fac<=(5/4))	//Lorentz Factor ~ 1 --> Non-relativistic (Electrons) --> Cyclotron Radiation
		{
			a.x= (q*((v.y*B.z)-(v.z*B.y)))/(m*c);	//Acceleration from Lorentz Force due to influence of B on the particle
			a.y= (q*((v.z*B.x)-(v.x*B.z)))/(m*c);
			a.z= (q*((v.x*B.y)-(v.y*B.x)))/(m*c);
			
			mag_a=magnitude(a);
			//P= (2*(pow(q,4))*(pow(mag_B,2))*(pow(b,2)))/(3*(pow(c,3))*(pow(m,2)));	//Larmor Formula for total Power radiated
			E=pow(mag_v,2);	//Energy= 1/2 mv^2
			
			fprintf(fp, "\n%lf, %lf, %lf, %lf, %lf, %lf", time, r.x, r.y, r.z, mag_r, E);
			printf("%-.4lf*10^(-7) s\t%.6lf cm\t%.6lf cm/s\t%.6lf*10^(7) cm/s^2\n", time/pow(10,-7), mag_r, mag_v, mag_a/pow(10,7));
			time+=t_int;
			
			r.x= r.x + v.x*t_int;
			r.y= r.y + v.y*t_int;
			r.z= r.z + v.z*t_int;
		
			v.x= v.x + a.x*t_int;
			v.y= v.y + a.y*t_int;
			v.z= v.z + a.z*t_int;
			
			mag_r=magnitude(r);
			mag_v=magnitude(v);
			
			//Euler's Method fails to take the curvature of the solution curve into account
			/*4th order Runge-Kutta Method is the most accurate of all, for finding the numerical solutions:: it is used for correcting the predicted value of the next solution point in the numerical solution*/	
		}
		else if(L_fac>=100)	//Lorentz Factor >> 1 --> Relativistic (Electrons) --> Synchrotron Radiation
		{
			printf("This is the case for Relativistic particles.\n");	//remove this line when block is decided
		}
	}
}

void main()
{
	char choice='y', ch;
	int sw;
	c= 2.99792458 * pow(10, 10);	//speed of light=2.99792458*10^(10) cm/s
	do
	{
		ch='n';
		choice='n';
		printf("Is the charged particle an electron? Y/N\n");
		scanf(" %c", &ch);
		if(ch=='y' || ch=='Y')
		{
			m= 9.10938356 * pow(10, -28);	//mass of electron=9.10938356*10^(-31)*10^3 g
			q= -(4.803204673 * pow(10, -10));	//charge of an electron=(1.6021766208*10^(-19))*c/10) statcoulomb
		}
		else
		{
			printf("Enter the mass and charge of the particle: ");
			scanf("%lf %lf", &m, &q);
			while(m<0)
			{
				printf("You entered invalid mass, Re-enter.\n");
				scanf("%lf", &m);
				continue;
			}
		}
		printf("Enter the x, y, and z components of the starting position and the initial velocity of the charged particle: ");
		scanf("%lf %lf %lf %lf %lf %lf", &r.x, &r.y, &r.z, &v.x, &v.y, &v.z);
		//enter exceptions (if any) herein (for both position and velocity) i--;
		printf("Would you like to enter values of the x, y and z components of the external magnetic field in (Select option):\n1. SI units\t\t2. CGS units\t");	//currently considering constant external magnetic field only along z direction
		scanf("%d", &sw);
		while(sw!=1 && sw!=2)
		{
			printf("Invalid Selection. Re-enter value.\n");
			scanf("%d", &sw);
		}
		printf("Enter the x, y and z components of the external magnetic field in which the charged particle is placed: ");
		scanf("%lf %lf %lf", &B.x, &B.y, &B.z);
		switch(sw)
		{
			case 1: B.x=(10000*B.x);	//alter to fit in all values entered in SI units
				B.y=(10000*B.y);	//converting from SI units to CGS units {Tesla=10000 gauss}
				B.z=(10000*B.z);
				break;
			case 2: break;
		}
		//enter exceptions (if any) herein i--;
		mag_r=magnitude(r);
		mag_v=magnitude(v);
		mag_B=magnitude(B);
		
		fp= fopen("plot.csv","w+");
		fprintf(fp, "Time, X-Coordinate, Y-Coordinate, Z-Coordinate, Magnitude of Position Vector, Energy change");
		printf("\nSo, for a charged particle of\nmass  %lf*10^(-28) grams,\ncharge  %lf*10^(-10) statcoulomb,\nmoving with velocity (given by the vector)  %.2lfx+%.2lfy+%.2lfz\nfrom a point  (%.2lf, %.2lf, %.2lf)\nin an external magnetic field (given by the vector)  %.2lf*10^(8)x+%.2lf*10^(8)y+%.2lf*10^(8)z\nof magnitude  %.6lf*10^(8) gauss,\nthe trajectory can be plotted as shown in the \"plot.csv\" file: \n", m/pow(10,-28), q/pow(10,-10), v.x, v.y, v.z, r.x, r.y, r.z, B.x/pow(10,8), B.y/pow(10,8), B.z/pow(10,8), mag_B/pow(10,8));
		
		compute();
		fclose(fp);
		
		printf("Do you want to compute the trajectory of another particle? Y/N\n");
		scanf(" %c", &choice);
	}while(choice=='y' || choice=='Y');
}
