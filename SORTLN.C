/*Dyakonov Nickolay, ND4 , 21.10.2020*/
#include "SORT.h"
#include <string.h>

static float *B;

/* Start of static 'Merge sort recursion' func */
static void MergeSortRec( float *A, int Size )
{
  int M, i, k, j;
  if (Size < 2)
    return;
  M = Size / 2;
  MergeSortRec(A, M);
  MergeSortRec(A + M, Size - M);
  for (k = 0, i = 0, j = M; k < Size; ++k)
  {
    if (j >= Size || i < M && A[i] < A[j])
      B[k] = A[i++];
    else
      B[k] = A[j++];
  }
  memcpy(A, B, sizeof A[0] * Size);
}
/*End of 'Merge sort recursion' func */

/* Start of 'Merge sort' func */
void MergeSort( float *A, int Size )
{
  B = malloc(sizeof(float) * Size);
  if (B == NULL)
    return;
  MergeSortRec(A, Size);
  free(B);
}
/*End of 'Merge sort' func */

/*Start of 'Quick sort' func */
void QuickSort( float *A, int Size )
{
  int b = 0, e = Size - 1;
  float x;

  if (Size < 2)
    return;
  
  x = A[Size / 2];

  while (b <= e)
  {
    while (A[b] < x)
      b++;
    while (A[e] > x)
      e--;
    if (b <= e)
    {
      if (b != e)
        Swap(&A[b], &A[e]);
      b++;
      e--;
    }
  }
  if (CheckSort(A, Size))
    return;
  QuickSort(A, e + 1);
  QuickSort(A + b, Size - b);
}
/*End of 'Quick sort' func */

/* Start of 'Heap correction' func */
void HeapCorrection( float *A, int Size, int i )
{
  while (1)
  {
    int 
      left = 2 * i + 1, 
      right = 2 * i + 2, 
      big = i;

    if (left < Size && A[i] < A[left])
      big = left;

    if (right < Size && A[big] < A[right])
      big = right;

    if (big == i)
      return;

    Swap(&A[i], &A[big]);
    i = big;
  }
}
/* End of 'Heap correction' func */


/* Start of 'Heap sort' func */
void HeapSort( float *A, int Size )
{
  int i;

  for (i = Size / 2 - 1; i >= 0; i--)
    HeapCorrection(A, Size, i);

  for (i = 0; i < Size - 1; i++)
  {
    Swap(&A[0], &A[Size - 1 - i]);
    HeapCorrection(A, Size - i - 1, 0);
  }
}
/* End of 'Heap sort' func */