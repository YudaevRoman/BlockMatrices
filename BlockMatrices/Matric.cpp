/*
Here the logic of matrices is described
*/

#include "Matric.h"
#include <omp.h>
#include <cmath>
#include <iostream>

using namespace std;

/*
Global variables
*/

int size_xA = 0, size_yA_xB = 0, size_yB = 0, blockMatrcSize = 1;

int* matricA = nullptr, * matricB = nullptr, * matricC = nullptr;

/*
Internal functions of the matrices are described.
*/

void IndexFromBlockToXY(int index, int& x, int& y) {
    x = index / Matrices_GetBlockMatricSize();
    y = index - x * Matrices_GetBlockMatricSize();
}

void BlockIndexToXY(int index, int& x, int& y) {
    x = index / 
            (int)ceil(
                (double)Matrices_GetSize_yB() / 
                (double)Matrices_GetBlockMatricSize());
    y = index - x *
        (int)ceil(
            (double)Matrices_GetSize_yB() /
            (double)Matrices_GetBlockMatricSize());
}

void Multiplication_Standard(int xA, int yA, int xB, int yB, int xC, int yC) {

    for (int i = 0; i < Matrices_GetBlockMatricSize() && xA + i < Matrices_GetSize_xA(); i++) {
        for (int j = 0; j < Matrices_GetBlockMatricSize() && yB + j < Matrices_GetSize_yB(); j++) {
            for (int count = 0; 
                count < Matrices_GetBlockMatricSize() && 
                yA + count < Matrices_GetSize_yA_xB() && 
                xB + count < Matrices_GetSize_yA_xB(); count++) {

                MatricC_SetItem( xC + i, yC + j, 
                    MatricC_GetItem(xC + i, yC + j) + 
                    MatricA_GetItem(xA + i, yA + count) * 
                    MatricB_GetItem(xB + count, yB + j));
            }
        }
    }
}

void Multiplication_Parallel(int xA, int yA, int xB, int yB, int xC, int yC) {

    int count, x, y, i, indexMax;
    indexMax = Matrices_GetBlockMatricSize() * Matrices_GetBlockMatricSize();

#pragma omp parallel private(count, x, y, i)
    {
#pragma omp for private(count, x, y, i)
        for (i = 0; i < indexMax; i++) {

            IndexFromBlockToXY(i, x, y);

            if (xA + x < Matrices_GetSize_xA()) {
                if (yB + y < Matrices_GetSize_yB()) {
                    for (count = 0;
                        count < Matrices_GetBlockMatricSize() &&
                        yA + count < Matrices_GetSize_yA_xB() &&
                        xB + count < Matrices_GetSize_yA_xB(); count++) {

                        MatricC_SetItem(xC + x, yC + y,
                            MatricC_GetItem(xC + x, yC + y) +
                            MatricA_GetItem(xA + x, yA + count) *
                            MatricB_GetItem(xB + count, yB + y));
                    }
                }
            }
        }
    }
}

/*
Functions for accessing and setting values of variable matrices
*/

int Matrices_GetSize_xA() {
    return size_xA;
}

int Matrices_GetSize_yA_xB() {
    return size_yA_xB;
}

int Matrices_GetSize_yB() {
    return size_yB;
}

void Matrices_SetSize_xA(int _size_xA) {
    size_xA = _size_xA;
}

void Matrices_SetSize_yA_xB(int _size_yA_xB) {
    size_yA_xB = _size_yA_xB;
}

void Matrices_SetSize_yB(int _size_yB) {
    size_yB = _size_yB;
}

bool Matrices_SizeEmpty() {
    if (Matrices_GetSize_xA() > 0 || 
        Matrices_GetSize_yA_xB() > 0 || 
        Matrices_GetSize_yB() > 0) {
        return false;
    }
    return true;
}

bool MatricA_Empty() {
    return !((bool)matricA);
}

bool MatricB_Empty() {
    return !((bool)matricB);
}

bool MatricC_Empty() {
    return !((bool)matricC);
}

int MatricA_GetItem(int x, int y) {
    if (!MatricA_Empty()) {
        return matricA[x * Matrices_GetSize_yA_xB() + y];
    }
    return 0;
}

int MatricB_GetItem(int x, int y) {
    if (!MatricB_Empty()) {
        return matricB[x * Matrices_GetSize_yB() + y];
    }
    return 0;
}

int MatricC_GetItem(int x, int y) {
    if (!MatricC_Empty()) {
        return matricC[x * Matrices_GetSize_yB() + y];
    }
    return 0;
}

void MatricA_SetItem(int x, int y, int item) {
    if (!MatricA_Empty()) {
        matricA[x * Matrices_GetSize_yA_xB() + y] = item;
    }
}

void MatricB_SetItem(int x, int y, int item) {
    if (!MatricB_Empty()) {
        matricB[x * Matrices_GetSize_yB() + y] = item;
    }
}

void MatricC_SetItem(int x, int y, int item) {
    if (!MatricC_Empty()) {
        matricC[x * Matrices_GetSize_yB() + y] = item;
    }
}

void MatricA_Init() {
    if (!MatricA_Empty()) {
        MatricA_Delete();
    }
    matricA = new int[Matrices_GetSize_xA() * Matrices_GetSize_yA_xB()];
}

void MatricB_Init() {
    if (!MatricB_Empty()) {
        MatricB_Delete();
    }
    matricB = new int[Matrices_GetSize_yA_xB() * Matrices_GetSize_yB()];
}

void MatricC_Init() {
    if (!MatricC_Empty()) {
        MatricC_Delete();
    }
    matricC = new int[Matrices_GetSize_xA() * Matrices_GetSize_yB()];
}

void MatricA_Delete() {
    if (!MatricA_Empty()) {
        delete[] matricA;
        matricA = nullptr;
    }
}

void MatricB_Delete() {
    if (!MatricB_Empty()) {
        delete[] matricB;
        matricB = nullptr;
    }
}

void MatricC_Delete() {
    if (!MatricC_Empty()) {
        delete[] matricC;
        matricC = nullptr;
    }
}

void MatricA_Clear() {
    if (!MatricA_Empty()) {
        for (int i = 0; i < Matrices_GetSize_xA(); i++) {
            for (int j = 0; j < Matrices_GetSize_yA_xB(); j++) {
                MatricA_SetItem(i, j, 0);
            }
        }
    }
}

void MatricB_Clear() {
    if (!MatricB_Empty()) {
        for (int i = 0; i < Matrices_GetSize_yA_xB(); i++) {
            for (int j = 0; j < Matrices_GetSize_yB(); j++) {
                MatricB_SetItem(i, j, 0);
            }
        }
    }
}

void MatricC_Clear() {
    if (!MatricC_Empty()) {
        for (int i = 0; i < Matrices_GetSize_xA(); i++) {
            for (int j = 0; j < Matrices_GetSize_yB(); j++) {
                MatricC_SetItem(i, j, 0);
            }
        }
    }
}

int Matrices_GetBlockMatricSize() {
    return blockMatrcSize;
}

void Matrices_SetBlockMatricSize(int _blockMatricSize) {
    blockMatrcSize = _blockMatricSize;
}


/*
Block multiplication
*/

double Matrices_MultiplicationStandard() {
    
    double startTime = omp_get_wtime();

    MatricC_Clear();

    for (int i = 0; i < Matrices_GetSize_xA(); i += Matrices_GetBlockMatricSize()) {
        for (int j = 0; j < Matrices_GetSize_yB(); j += Matrices_GetBlockMatricSize()) {
            for (int count = 0; count < Matrices_GetSize_yA_xB(); count += Matrices_GetBlockMatricSize()) {
                Multiplication_Standard(i, count, count, j, i, j);
            }
        }
    }

    return omp_get_wtime() - startTime;
}

double Matrices_MultiplicationParallel_Up() {

    double startTime = omp_get_wtime();

    int count, x, y, i, indexMax;
    indexMax = 
        (int)ceil((double)Matrices_GetSize_xA() / (double)Matrices_GetBlockMatricSize()) *
        (int)ceil((double)Matrices_GetSize_yB() / (double)Matrices_GetBlockMatricSize());

    MatricC_Clear();

#pragma omp parallel private(count, x, y, i)
    {
#pragma omp for private(count, x, y, i)
        for (i = 0; i < indexMax; i++) {
            BlockIndexToXY(i, x, y);
            x *= Matrices_GetBlockMatricSize();
            y *= Matrices_GetBlockMatricSize();

            for (count = 0; count < Matrices_GetSize_yA_xB(); count += Matrices_GetBlockMatricSize()) {
                Multiplication_Standard(x, count, count, y, x, y);
            }
        }
    }

    return omp_get_wtime() - startTime;
}

double Matrices_MultiplicationParallel_Down() {

    double startTime = omp_get_wtime();

    MatricC_Clear();

    for (int i = 0; i < Matrices_GetSize_xA(); i += Matrices_GetBlockMatricSize()) {
        for (int j = 0; j < Matrices_GetSize_yB(); j += Matrices_GetBlockMatricSize()) {
            for (int count = 0; count < Matrices_GetSize_yA_xB(); count += Matrices_GetBlockMatricSize()) {
                Multiplication_Parallel(i, count, count, j, i, j);
            }
        }
    }

    return omp_get_wtime() - startTime;
}

double Matrices_MultiplicationParallel_All() {

    double startTime = omp_get_wtime();

    int count, x, y, i, indexMax;
    indexMax =
        (int)ceil((double)Matrices_GetSize_xA() / (double)Matrices_GetBlockMatricSize()) *
        (int)ceil((double)Matrices_GetSize_yB() / (double)Matrices_GetBlockMatricSize());

    MatricC_Clear();

    omp_set_nested(1);

#pragma omp parallel private(count, x, y, i)
    {
#pragma omp for private(count, x, y, i)
        for (i = 0; i < indexMax; i++) {
            BlockIndexToXY(i, x, y);
            x *= Matrices_GetBlockMatricSize();
            y *= Matrices_GetBlockMatricSize();

            for (count = 0; count < Matrices_GetSize_yA_xB(); count += Matrices_GetBlockMatricSize()) {
                Multiplication_Parallel(x, count, count, y, x, y);
            }
        }
    }

    omp_set_nested(0);

    return omp_get_wtime() - startTime;
}