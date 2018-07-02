#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank;
    int array[8][8];
    int a_count=8;
    int a_blocklength=1;
    int a_stride=8;
    MPI_Status status;
    
    //TODO: Declare a variable storing the MPI datatype
    MPI_Datatype typea;

    int i, j;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Initialize arrays
    if (rank == 0) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = (i + 1) * 10 + j + 1;
            }
        }
    } else {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = 0;
            }
        }
    }

    if (rank == 0) {
        printf("Data in rank 0\n");
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                printf("%3d", array[i][j]);
            }
            printf("\n");
        }
    }


    //TODO: Create datatype that describes one column. Use MPI_Type_vector.
      // Create datatype
    MPI_Type_vector(a_count, a_blocklength, a_stride, MPI_INT, &typea);
    MPI_Type_commit(&typea);

    // Send first column of matrix
    if (rank == 0) {
        MPI_Send(&array[0][1], a_blocklength, typea, 1, 1, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&array[0][1], a_blocklength, typea, 0, 1, MPI_COMM_WORLD,
                 &status);
    }

    // Print out the result
    if (rank == 1) {
        printf("Received data\n");
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                printf("%3d", array[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Type_free(&typea);
    MPI_Finalize();

    return 0;
}
