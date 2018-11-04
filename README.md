# Parallel-processing-1
My goal is to solve this FIND SUM problem using ring logical topologies: a ring of k processorsring toplogy

ALL to all ring broadcast and reduce.


1. Load MPICH2 module before compiling the program. 
   <br> module load tools/mpich2-1.5-gcc

2. Compile the program 
   <br> cd ~/MPIsample 
   <br> mpicc -o mpitest mpitest.c
   
3. Modify netid references in email address & working directory in job script; 
   <br> e.g.: vi mpitest.pbs

4. Submit to the queue: 
   <br> qsub mpitest.pbs
   
   
   
   
   
<br> The first part.


<br> The second Part.
<br> chapter 9.Sorting
1. parllel sorting 
<br> PARM mesh hypercube
<br> 内排序算法 internal sort 外排序算法 external sort
<br>  在内排序算法中，排序元素的树木要足够少，使得他们能够放到进程的主储存器。相反，外排序利用辅助存储硬件（如磁盘和硬盘
来排序，只因待排序元素数目太多，不适合放进内存。
