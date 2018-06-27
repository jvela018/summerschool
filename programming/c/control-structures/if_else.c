#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
	
    // write the control structure as described in the exercise
	printf("Please Enter an Integer: \n");
	scanf("%d", &i);
	
	if((i<0)||(i==0)){
	  printf("The number must be positive and different than zero. Try again later\n");
	}
	else{
	  printf("Your number is %d: \n", i);
	}

    // and run the code with different values for i

    return 0;
}
