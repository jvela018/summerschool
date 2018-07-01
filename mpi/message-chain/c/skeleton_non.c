#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int i, myid, ntasks, count, dest,source,tag;
    int size = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status status;

    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Request request1;
    MPI_Request request2;

    /* Allocate message buffers */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++) {
        message[i] = myid;
    }

    /* Start measuring the time spent in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();

    /* TODO start */
    /* Send and receive messages as defined in exercise */ 
    
    //tag = 10;
    count = size;
    dest = myid+1;
    source = myid-1;
 
    if(myid < ntasks - 1){

      	MPI_Isend(message, count, MPI_INT, dest, myid+1, MPI_COMM_WORLD, &request1);
    }
    
    if (myid > 0) {				
	MPI_Irecv(receiveBuffer, count, MPI_INT,source,myid, MPI_COMM_WORLD, &request2);
    }
    	
    
    if (myid < ntasks - 1) {
        printf("Sender: %d. Sent elements: %d. Tag: %d. Receiver: %d\n",
               myid, size, myid + 1, myid + 1);
    }

    if (myid > 0) {

        printf("Receiver: %d. first element %d.\n",
               myid, receiveBuffer[0]);
    }

    /* TODO end */

    /* Finalize measuring the time and print it out */
    t1 = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    fflush(stdout);

    printf("Time elapsed in rank %2d: %6.3f\n", myid, t1 - t0);

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}
