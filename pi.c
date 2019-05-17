#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int argc,char** argv)
{
double point=10000;
double pi;
int tag;
double x,y;
double x1,y1;
int i,j;

int countcir=0;
int countcir1=0;
int myid;

int numprocs;
MPI_Status status;
MPI_Init(&argc,&argv);

MPI_Comm_rank(MPI_COMM_WORLD,&myid);
MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
srand(time(NULL));

if(myid==0){

for(i=0;i<point/2;i++){
x=((rand()%1000)+1)/1000.0;
y=((rand()%1000)+1)/1000.0;
//printf("x=%f y=%f i=%d\n",x,y,i);
if((x-0.5)*(x-0.5)+(y-0.5)*(y-0.5)<0.25){
countcir++;
}
}

printf("c0=%d\n",countcir);

MPI_Recv(&countcir1,1,MPI_INT,1,tag,MPI_COMM_WORLD,&status);
printf("c1=%d\n",countcir1);
countcir=countcir+countcir1;
printf("count total=%d\n",countcir);
pi=4*countcir/point;
printf("pi=%f\n",pi);
}
else{
//id1

for(j=0;j<point/2;j++){
x1=((rand()%1000)+1)/1000.0;
y1=((rand()%1000)+1)/1000.0;
//printf("x1=%f y1=%f j=%d \n",x1,y1,j);
if((x1-0.5)*(x1-0.5)+(y1-0.5)*(y1-0.5)<0.25){
countcir1++;
}
}



MPI_Send(&countcir1,1,MPI_INT,0,tag,MPI_COMM_WORLD);

}

MPI_Finalize();
return 0;
}
