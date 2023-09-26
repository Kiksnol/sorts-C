/*Dyakonov Nickolay, ND4 , 21.10.2020*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char *Name;
  void (*Func)( float *A, int Size );
} FUNCNAME;

/* Printing array on the screen */
void OutMas( float *Arr, int Size );

/* Filling array functions */
void FillRand( float *Arr, int Size );
void FillIncr( float *A, int Size );
void FillEq( float *A, int Size );
void FillDecr( float *A, int Size );
void FillMostly( float *A, int Size );

/* Two elements swap func */
void Swap( float *A, float *B );

/* Array correct check */
int CheckSort( float *A, int Size );

/* Different array sort types */
void BubbleSortAdv( float *A, int Size );
void InsertionSort( float *A, int Size );
void SelectionSort( float *A, int Size );
void BubbleShakerSort( float *A, int Size );
void MergeSort( float *A, int Size );
void QuickSort( float *A, int Size );
void HeapSort( float *A, int Size );