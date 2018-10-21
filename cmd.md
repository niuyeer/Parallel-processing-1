# The process to compile 

1. connect to extreme login

2. cd rm mkdir ls

3. vi

<br> set paste
<br> ESC 
<br> : A
<br> wq


4. module load tools/mpich2-1.5-gcc

5. mpicc -o test test.c

6. mpirun -n 4 ./test


