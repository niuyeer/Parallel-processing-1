#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>
#include "time.h"//clock() get time
#define SIZE 10000000
int array[SIZE];
//struct timeval start1,end1;// get time
int main(int argc, char ** argv){
   // gettimeofday(&start1,NULL);
    
    int myNode,allNodes;
    int  sum=0,accum=0,rootSum=0;
    
    int start,end;
    clock_t t1,t2,t3,t4,t5;
    MPI_Status status;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank( MPI_COMM_WORLD, &myNode);
    MPI_Comm_size( MPI_COMM_WORLD, &allNodes);
    int partialSum;
    //MPI_Barrier(MPI_COMM_WORLD);
    t1=clock();
    if (myNode==0)
    {
        
        //create array
        int n;
        srand((unsigned)time(NULL));
        for (n=0;n<SIZE;n++)
        {
            array[n]=rand()%10;
            //printf("number %d , %d process\n", array[n],myNode);
        }
        
        
    }
    t2=clock();
    //find neighbour
    int prev,next;
    next=myNode+1;
    if (next>=allNodes){
        next=0;}
    //printf("next %d calculated by %d process\n", next,myNode);
    
    prev=myNode-1;
    if (prev<0) {
        prev=allNodes-1;}
   // printf("prev %d calculated by %d process\n", prev,myNode);
    //printf(" %d calculated by %d process\n", array[99],myNode);
    //send array
   if (myNode==0) {
            MPI_Send( &array, SIZE, MPI_INT, next, 0, MPI_COMM_WORLD );
            MPI_Recv( &array, SIZE, MPI_INT, prev, 0, MPI_COMM_WORLD,&status );
        
        }
    else{
            MPI_Recv( &array, SIZE, MPI_INT, prev, 0, MPI_COMM_WORLD,&status );
            MPI_Send( &array, SIZE, MPI_INT, next, 0, MPI_COMM_WORLD );
        }
    
    /*divde*/
    t3=clock();
    int i;
    partialSum=0;
    start = SIZE*myNode/allNodes;
    end = SIZE*(myNode+1)/allNodes-1;
    if (myNode==allNodes-1)
    {
        end=SIZE-1;
    }
    
    for(i=start;i<=end;i++)
    {
        partialSum+=array[i];
    }
    printf("partial sum %d calculated by %d process\n", partialSum,myNode);
    t4=clock();
   
   // printf("time=%d us from node%d\n",difftime(clock(),t1),myNode);
   MPI_Reduce(&partialSum, &accum, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    t5=clock();
   /* int temp,recv;
    int msg[allNodes];
    msg[myNode]=partialSum;
    int j;
    for (i=0; i<=allNodes-1; i++) {
       j=(myNode+i)%allNodes;
        temp=msg[j]+recv;
        MPI_Send( &temp, SIZE, MPI_INT, prev, 0, MPI_COMM_WORLD );
        MPI_Recv( &recv, SIZE, MPI_INT, next, 0, MPI_COMM_WORLD,&status );
    }
    accum=msg[myNode]+recv;*/
   
  
   // MPI_Barrier(MPI_COMM_WORLD);
    printf("total time=%d us from node%d\n",t5-t1,myNode);
    printf("calcualtion time=%d us from node%d\n",t2-t1+t4-t3,myNode);
    printf("communication time=%d us from node%d\n",t5-t4+t3-t2,myNode);
    
    if(myNode==0){
        printf("pross=%d sum=%d\n",myNode,accum);
       // gettimeofday(&end1,NULL);
       // double timeUse = end1.tv_sec - start1.tv_sec + (end1.tv_usec - start1.tv_usec)/1000000.0;
       // printf("the total time is %d\n",timeUse);
      //  printf("It took me %d clicks (%f seconds) from node%d\n",t3,((float)t3)/CLOCKS_PER_SEC,myNode);
    }
  
 
    MPI_Finalize();
    return 0;
}

