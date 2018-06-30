#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[])
{
    int omp_rank;
    printf("Hello world!\n");
    #pragma omp parallel shared(omp_rank)
    {
	omp_rank = omp_get_thread_num();
        printf("X by thread %d\n", omp_rank);
    }

    return 0;
}
