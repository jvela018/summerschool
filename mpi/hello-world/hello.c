#include <stdio.h>
#include <mpi.h>

int main(void){

//int rank;

MPI_Init(NULL,NULL);

int rank;
int size; 

MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

printf("Hello World!from process %d ", rank);

if(rank==0){
 printf("(size %d) \n", size);
}else{
 printf("\n");
}

MPI_Finalize();

return 0;
}
