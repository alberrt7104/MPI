#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "math.h"
#include "mpi.h"
int main(int argc,char** argv)
{
int taskid, ntasks;
int ierr,i,j,itask;
int buffsize;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
MPI_Comm_size(MPI_COMM_WORLD,&ntasks);
if ( taskid == 0 ){
printf("\n\n\n\n\n");
}
ierr=MPI_Barrier(MPI_COMM_WORLD);
if ( taskid == 0 )printf("Hel");
ierr=MPI_Barrier(MPI_COMM_WORLD);
if ( taskid == 1 )printf("lo ");
ierr=MPI_Barrier(MPI_COMM_WORLD);
if ( taskid == 2 )printf("Wor");
ierr=MPI_Barrier(MPI_COMM_WORLD);
if ( taskid == 3 )printf("ld!");
ierr=MPI_Barrier(MPI_COMM_WORLD);
if ( taskid == 0 ){
printf(" (Ordered)\n\n\n\n\n");
}
MPI_Finalize();
}
