#pragma once
/*
Here are the prototypes of the functions for working with the menu
*/

/// <summary>
/// Program menu starts.
/// </summary>
void Menu_Start();

/// <summary>
/// Matrices set menu item.
/// </summary>
void Menu_SetMatrices();

/// <summary>
/// Set the size of the matrices.
/// </summary>
void SetMatrices_SetSize();

/// <summary>
/// Set the matrix A.
/// </summary>
void SetMatrices_SetMatricA();

/// <summary>
/// Set the matrix B.
/// </summary>
void SetMatrices_SetMatricB();

/// <summary>
/// Set matrices A and B with random values.
/// </summary>
void SetMatrices_SetMatricesRandom();

/// <summary>
/// Output matrices.
/// </summary>
void Menu_ShowMatrices();

/// <summary>
/// Perform matrix multiplication.
/// </summary>
void Menu_ExecuteMultiplication();

/// <summary>
/// Set the size of the matrix block.
/// </summary>
void ExecuteMultiplication_SetBlockSize();

/// <summary>
/// Block multiplication without parallelism. 
/// </summary>
void ExecuteMultiplication_Standard();

/// <summary>
/// Block multiplication with upper level parallelism. 
/// </summary>
void ExecuteMultiplication_Parallel_Up();

/// <summary>
/// Block multiplication with lower level parallelism. 
/// </summary>
void ExecuteMultiplication_Parallel_Down();

/// <summary>
/// Block multiplication with full parallelism. 
/// </summary>
void ExecuteMultiplication_Parallel_All();