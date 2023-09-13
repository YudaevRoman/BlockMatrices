Performing block matrix multiplication in C++ using parallelism. 

The program multiplies matrix A by matrix B. The result of the multiplication is output to the matrix C. 

The program is designed for 4 types of execution: performing ordinary block multiplication, performing block multiplication using parallelism at the upper level (parallelization of blocks), using parallelism at the lower level (parallelization of the multiplication operation of blocks), using full parallelism (lower and upper levels).

Please note that for large matrix sizes, you should disable the display of matrices on the display, since their output may be large and not informative.

#Test push