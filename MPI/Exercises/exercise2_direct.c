#include <stdio.h>
#include "mpi.h"

void main(int argc, char** argv){
	int num_PEs;
	MPI_Status status;
	//initialize MPI
	MPI_Init(&argc, &argv);
	
	// get number of processes
	MPI_Comm_size(MPI_COMM_WORLD,&num_PEs);

	printf("--> Running on %d PEs.\n",num_PEs);
	
	//exit MPI
	MPI_Finalize();
}