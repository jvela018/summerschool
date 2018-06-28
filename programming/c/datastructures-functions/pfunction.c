#include <stdio.h>

int add_one_to_both(int *num1, int *num2) {

   int fnum1, fnum2;
 
   fnum1 = ++(*num1);		
   fnum2 = ++(*num2);
 
   return (fnum1, fnum2); 
}

int main(int argc, char *argv[])
{
    int a=10, b=20;

    add_one_to_both(&a, &b);
   
    printf("a=%d \n", a);
    printf("b=%d \n", b);
   
   return 0;
}


