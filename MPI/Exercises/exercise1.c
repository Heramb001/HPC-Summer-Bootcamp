#include <stdio.h>
#include "mpi.h"

void main(int argc, char** argv ){
	int my_PE_num, num_process, num_to_send, msg_recieved;
	MPI_Status status;
	
	//Start MPI
	MPI_Init(&argc, &argv);
	//get id
	MPI_Comm_rank(MPI_COMM_WORLD, &my_PE_num);
	//get number of process
	MPI_Comm_size(MPI_COMM_WORLD, &num_process)
	// assign the number to be send to be the PE_number of current node
	num_to_send = my_PE_num;
	
	//Sending the messages
	if(my_PE_num==&num_process-1)
		// if node = 7 pass the message to 0 to make it a circular shift.
		MPI_Send(&num_to_send, 1, MPI_INT, 0, 10, MPI_COMM_WORLD);
	else
		// else send the message to the next adjacent node;
		MPI_Send(&num_to_send, 1, MPI_INT, my_PE_NUM+1, 10, MPI_COMM_WORLD);
	
	// recieve the bytes
	MPI_Recv(&msg_recieved, 1, MPI_INT, MPI_ANY_SOURCE, 10, MPI_COMM_WORLD, &status);
	
	//print the recieved message along with the PE_number
	printf("PE %d recieved from %d.\n", my_PE_num, msg_recieved);
	
	// End MPI 
	MPI_Finalize();
}