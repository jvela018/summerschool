#include <stdio.h>
#include <omp.h>

int main(void)
{
    int var1 = 1, var2 = 2;
    int omp_rank;	
    
#pragma omp parallel private(var1)
    {	
	int var1=50;
	//omp_rank = omp_get_thread_num();
        printf("Private Region 1: var1=%i, var2=%i\n", var1, var2);
        var1++;
        var2++;
    }
    printf("After region 1 (Private): var1=%i, var2=%i\n\n", var1, var2);

#pragma omp parallel shared(var1)
    {
	int var1=2;
	//omp_rank = omp_get_thread_num();
        printf("Shared Region 1: var1=%i, var2=%i\n", var1, var2);
        var1++;
        var2++;
    }
    printf("After region 1 (Shared): var1=%i, var2=%i\n\n", var1, var2);



    return 0;
}
