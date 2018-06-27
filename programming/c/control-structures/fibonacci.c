#include <stdio.h>

int main(int argc, char *argv[])
{
    int f_n, f_1, f_2;

    // initialize variables and write the while loop

	f_1 = 1;
	f_2 = 1;
	printf("%d\n%d\n", f_1, f_2);
	f_n = f_1 + f_2;

	while (f_n<100) {
	printf("%d \n", f_n);
	f_1 = f_2; 
	f_2 = f_n;
	f_n = f_1 + f_2; }

    return 0;
}
