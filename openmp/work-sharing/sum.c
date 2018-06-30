#include <stdio.h>
#include <omp.h>
#define NX 102400

int main(void)
{
    double vecA[NX], vecB[NX], vecC[NX];
    double sum, sum_check;
    int i;


    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = 1.0 / ((double)(NX - i));
        vecB[i] = vecA[i] * vecA[i];
    }
sum_check = 0.0;
// Serial check
	for (i = 0; i < NX; i++) {
       	 sum_check += vecA[i] + vecB[i];
        }

#pragma omp parallel for default(shared) private(i)

        for (i = 0; i < NX; i++) {
         vecC[i] = vecA[i] + vecB[i];
        }

    sum = 0.0;
//    Compute the check value 
    for (i = 0; i < NX; i++) {
        sum = sum+vecC[i];
    }
    printf("Serial sum check: %18.16f\n", sum_check);
    printf("Reduction sum: %18.16f\n", sum);

    return 0;
}
