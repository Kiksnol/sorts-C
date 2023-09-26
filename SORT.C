/*Dyakonov Nickolay, ND4 , 21.10.2020*/
#include "SORT.h"

/* Start of 'Checking array to be sorted' func */
int CheckSort( float *A, int Size )
{
  int i = 0;

  for (; i < Size - 1; i++)
    if (A[i] > A[i + 1])
      return 0;
  return 1;
}
/* End of 'Checking array to be sorted' func */

/* Start of 'Advanced Bubble sort' func */
void BubbleSortAdv( float *A, int Size )
{
  int i, last = Size - 2, changed;

  do
  {
    for (changed = 0, i = 0; i <= last; i++)
      if (A[i + 1] < A[i])
        Swap(&A[i + 1], &A[i]), changed = i;
    last = changed - 1;
  }while (last >= 0);
}
/* End of 'Advanced Bubble sort' func */

/* Start of 'Insertion sort' func */
void InsertionSort( float *A, int Size)
{
  int i, j;
  float k;

  for (i = 1; i <= Size - 1; i++)
  {
    k = A[i];
    j = i - 1;
    while (j >= 0 && k < A[j])
      A[j + 1] = A[j], j--;
    A[j + 1] = k;
  }
}
/* End of 'Insertion sort' func */

/*Start of 'Selection sort' func */
void SelectionSort( float *A, int Size )
{
  int i, j, minim;

  for (j = 0; j <= Size - 2; j++) 
  {
    for (i = 1 + j, minim = j; i < Size; i++)
      if (A[i] < A[minim])
        minim = i;
    Swap(&A[j], &A[minim]);
  }
}
/*End of 'Selection sort' func */

/* Start of 'Bubble Shaker sort' func */
void BubbleShakerSort( float *A, int Size )
{
  int i, changed, lst = Size - 2, fst = 0;

  do
  {
   for (changed = fst, i = fst; i <= lst; i++)
     if (A[i] > A[i + 1])
       Swap(&A[i], &A[i + 1]), changed = i;
   lst = changed - 1;
   for (changed = lst, i = lst; i >= fst; i--)
     if (A[i] > A[i + 1])
       Swap(&A[i], &A[i + 1]), changed = i;
    fst = changed + 1;
  } while (lst >= fst);
}
/* End of 'Bubble Shaker sort' func */
