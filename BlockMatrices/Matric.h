#pragma once
/*
Here are the prototypes of the functions for working with the menu
*/

/// <summary>
/// Get the number of rows of matrix A.
/// </summary>
int Matrices_GetSize_xA();

/// <summary>
/// Get the number of columns of matrix A and rows of matrix B.
/// </summary>
int Matrices_GetSize_yA_xB();

/// <summary>
/// Get the number of columns of matrix B.
/// </summary>
int Matrices_GetSize_yB();

/// <summary>
/// Set the number of rows of matrix A.
/// </summary>
void Matrices_SetSize_xA(int _size_xA);

/// <summary>
/// Set the number of columns of matrix A and rows of matrix B.
/// </summary>
void Matrices_SetSize_yA_xB(int _size_yA_xB);

/// <summary>
/// Set the number of columns of matrix B.
/// </summary>
void Matrices_SetSize_yB(int _size_yB);

/// <summary>
/// Checking for the existence of the size of matrices.
/// </summary>
bool Matrices_SizeEmpty();

/// <summary>
/// Check whether the matrix A exists.
/// </summary>
bool MatricA_Empty();

/// <summary>
/// Check whether the matrix B exists.
/// </summary>
bool MatricB_Empty();

/// <summary>
/// Check whether the matrix C exists.
/// </summary>
bool MatricC_Empty();

/// <summary>
/// Get the matrix element A.
/// </summary>
int MatricA_GetItem(int x, int y);

/// <summary>
/// Get the matrix element B.
/// </summary>
int MatricB_GetItem(int x, int y);

/// <summary>
/// Get the matrix element C.
/// </summary>
int MatricC_GetItem(int x, int y);

/// <summary>
/// Set the matrix element A.
/// </summary>
void MatricA_SetItem(int x, int y, int item);

/// <summary>
/// Set the matrix element B.
/// </summary>
void MatricB_SetItem(int x, int y, int item);

/// <summary>
/// Set the matrix element C.
/// </summary>
void MatricC_SetItem(int x, int y, int item);

/// <summary>
/// Allocates memory for matrix A.
/// </summary>
void MatricA_Init();

/// <summary>
/// Allocates memory for matrix B.
/// </summary>
void MatricB_Init();

/// <summary>
/// Allocates memory for matrix C.
/// </summary>
void MatricC_Init();

/// <summary>
/// Clears the allocated memory of the matrix A.
/// </summary>
void MatricA_Delete();

/// <summary>
/// Clears the allocated memory of the matrix B.
/// </summary>
void MatricB_Delete();

/// <summary>
/// Clears the allocated memory of the matrix C.
/// </summary>
void MatricC_Delete();

/// <summary>
/// The matrix A is zeroed.
/// </summary>
void MatricA_Clear();

/// <summary>
/// The matrix B is zeroed.
/// </summary>
void MatricB_Clear();

/// <summary>
/// The matrix C is zeroed.
/// </summary>
void MatricC_Clear();

/// <summary>
/// Get the size of the matrix partitioning blocks.
/// </summary>
int Matrices_GetBlockMatricSize();

/// <summary>
/// Get the size of the matrix partitioning blocks.
/// </summary>
void Matrices_SetBlockMatricSize(int _blockMatricSize);

/// <summary>
/// Perform block multiplication using the standard algorithm.
/// Returns the time for which the operation was performed.
/// </summary>
double Matrices_MultiplicationStandard();

/// <summary>
/// Perform block multiplication using a parallel algorithm.
/// Upper level.
/// Returns the time for which the operation was performed.
/// </summary>
double Matrices_MultiplicationParallel_Up();

/// <summary>
/// Perform block multiplication using a parallel algorithm.
/// Lower level.
/// Returns the time for which the operation was performed.
/// </summary>
double Matrices_MultiplicationParallel_Down();

/// <summary>
/// Perform block multiplication using a parallel algorithm.
/// Full.
/// Returns the time for which the operation was performed.
/// </summary>
double Matrices_MultiplicationParallel_All();