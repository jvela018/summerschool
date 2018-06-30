#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
    int i, myid, ntasks, count, dest, source;
    int size = 1000;
    int *message;
    int *receiveBuffer;
        

    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++) {
        message[i] = myid;
    }

    /* TODO: */
    /* Send and receive messages as defined in exercise */
    count = size;
    dest = ntasks-1;
    source = 0; 
    
    if(myid==0){
    MPI_Send(message      , count, MPI_INT, dest  , 1, MPI_COMM_WORLD);
    }
    if(myid == ntasks-1){
    MPI_Recv(receiveBuffer, count, MPI_INT, source, 1, MPI_COMM_WORLD, &status);
    }	


    if (myid == 0) {

        printf("Rank %i received %i\n", myid, receiveBuffer[0]);
    } else if (myid == 1) {

        printf("Rank %i received %i\n", myid, receiveBuffer[0]);
    }

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}
