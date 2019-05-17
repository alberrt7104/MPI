#include "mpi.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
int passenger=30;
int capacity=5;
int rollercoaster=0;
int isempty=0;
int i;
int tag;
int numprocs;
int myid;
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
MPI_Comm_rank(MPI_COMM_WORLD,&myid);

if(myid==0){

rollercoaster=0;
isempty=0;
printf("roller coaster is empty\n");
MPI_Send(&isempty,1,MPI_INT,1,tag,MPI_COMM_WORLD);
while(passenger>0){
MPI_Recv(&passenger,1,MPI_INT,1,MPI_ANY_TAG,MPI_COMM_WORLD,&status);


rollercoaster=capacity;
isempty=1;
printf("roller coaster is full has 5 people ont the rooler coaster\n");
MPI_Send(&isempty,1,MPI_INT,1,tag,MPI_COMM_WORLD);
usleep(1000000);

rollercoaster=0;
isempty=0;
printf("roller coaster is empty\n");
MPI_Send(&isempty,1,MPI_INT,1,tag,MPI_COMM_WORLD);


}
printf("no passenger\n");
}
else{
// my id==1 
while(passenger>0){
MPI_Recv(&isempty,1,MPI_INT,0,tag,MPI_COMM_WORLD,&status);
if(isempty==0){
printf("now has %d\n",passenger);
passenger=passenger-capacity;

MPI_Send(&passenger,1,MPI_INT,0,tag,MPI_COMM_WORLD);

}
else{

printf("roller coaster is full please wait\n");
}

}
}
MPI_Finalize();
return 0;
}
