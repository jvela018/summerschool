#include <stdio.h>

int main(int argc, char *argv[])
{
    // declare integers, floats, and doubles
	int 	a=1, b=5;
	float 	c;
	double	d;	

    // evaluate expressions, e.g. c = a + 2.5 * b
	c = a + 2.5*1e-12*b;
	d = a + 2.5*1e-12*b;

    // and print out results. Try to combine integers, floats
	printf("We are computing c = a + 2.5 * b \n");
	printf("AND we are computing d = a + 2.5 * b \n");
	printf("Integers: a=%d and b= %d \n",a,b);
	printf("Float: c= %f \n",c);
	printf("Double: d= %f \n",d);
	
    // and doubles and investigate what happens in type conversions

    return 0;
}
