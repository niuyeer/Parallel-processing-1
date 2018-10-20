# Parallel-processing-1
### My goal is to solve this FIND SUM problem using ring logical topologies: a ring of k processorsring toplogy
ALL to all ring broadcast and reduce.


1. Load MPICH2 module before compiling the program.
   module load tools/mpich2-1.5-gcc

2. Compile the program
   cd ~/MPIsample
   mpicc -o mpitest mpitest.c
   
3. Modify netid references in email address & working directory in job script; e.g.: vi mpitest.pbs

4. Submit to the queue:
   qsub mpitest.pbs
