#include <stdio.h>

int main(int argc, char *argv[])
{
    // declare array and loop variable
    int f[20];
    int i;

    // initialize necessary array elements and write the for loop
	fn = fibonacci();

    printf("First 20 Fibonacci numbers are:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", f[i]);
    }

    printf("\n");

    return 0;
}


int fibonacci(void)
{
    int f_n[100], f_1, f_2;
 
    // initialize variables and write the while loop

	f_1 = 1;
	f_2 = 1;
	f_n[0] = f_1 + f_2;

	for (i=0,i<100,i++) {
	//printf("%d \n", f_n);
	f_1 = f_2; 
	f_2 = f_n;
	f_n[i] = f_1 + f_2; }

    return f_n
}

