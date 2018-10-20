# Parallel-processing-1
My goal is to solve this FIND SUM problem using ring logical topologies: a ring of k processorsring toplogy

ALL to all ring broadcast and reduce.


1. <br> Load MPICH2 module before compiling the program. ＜/br＞
   module load tools/mpich2-1.5-gcc

2. <br> Compile the program ＜/br＞
   <br> cd ~/MPIsample ＜/br＞
   mpicc -o mpitest mpitest.c
   
3. <br> Modify netid references in email address & working directory in job script; ＜/br＞
   e.g.: vi mpitest.pbs

4. <br> Submit to the queue: ＜/br＞
   qsub mpitest.pbs
