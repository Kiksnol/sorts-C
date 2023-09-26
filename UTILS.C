/*Dyakonov Nickolay, ND4 , 21.10.2020*/
#include "SORT.h"

/* Start of 'Array Outputting' func */
void OutMas( float *Arr, int Size )
{
  int i = 0;

  for (; i < Size; i++)
    printf("%f\n", Arr[i]);
}
/* End of 'Array Outputting' func */

/* Start of 'Filling array with random numbers' func */
void FillRand( float *Arr, int Size )
{
  int i = 0;

  for (; i < Size; i++)
    Arr[i] = (float)((rand() - RAND_MAX / 2) / 106.2);
}
/* End of 'Filling array with random numbers' func */

/* Start of 'Filling array with increasing numbers' func */
void FillIncr( float *A, int Size )
{
  int i;

  for (A[0] = 31.0, i = 1; i < Size; i++)
    A[i] = (float)(A[i - 1] + rand() % 100 / 8.0);
}
/* End of 'Filling array with increasing numbers' func */

/* Start of 'Filling array with decreasing numbers' func */
void FillDecr( float *A, int Size )
{
  int i;

  for (A[0] = 1030.0, i = 1; i < Size; i++)
    A[i] = (float)(A[i - 1] - rand() % 100 / 8.0);
}
/* End of 'Filling array with decreasing numbers' func */

/* Start of 'Swapping' func */
void Swap( float *A, float *B )
{
  float tmp = *A;

  *A = *B, *B = tmp;
}
/* End of 'Swapping' func */

/* Start of 'Swapping 5% of array' func */
void FillMostly( float *A, int Size )
{
  int i = 0;

  FillIncr(A, Size);
  
  for (; i < Size / 20; i++)
    Swap(&A[rand() % Size], &A[rand() % Size]);
}
/* End of 'Swapping 5% of array' func */

/* Start of 'Filling array with equal numbers' func */
void FillEq( float *A, int Size )
{
  int i;
  float p = (float)((rand() - RAND_MAX / 2) % 1000 * 2.313134 / 3.42341 + 0.00001);

  for (i = 0; i < Size; i++)
    A[i] = p;
}
/* End of 'Filling array with equal numbers' func */