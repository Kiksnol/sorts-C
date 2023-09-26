/*Dyakonov Nickolay, ND4 , 21.10.2020*/
#include "SORT.h"
#include <time.h>

#define MAX 10000000

void main( void )
{
  static float mas[MAX];
  int si, fi, t;

  FUNCNAME Sort[] =
  {
    {"Quick", QuickSort},
    {"Heap", HeapSort},
    {"Merge", MergeSort}
  };
  FUNCNAME Fill[] = 
  {
    {"FillIncr", FillIncr},
    {"FillDecr", FillDecr},
    {"FillRand", FillRand},
    {"FillEqua", FillEq},
    {"FillMost", FillMostly}
  };
  
  printf("Amount of elements: %d\n", MAX);

  for (si = 0; si < sizeof(Sort) / sizeof(Sort[0]); si++)
  {
    printf("Sort: %s\n", Sort[si].Name);
    for (fi = 0; fi < sizeof(Fill) / sizeof(Sort[0]); fi++)
    {
      Fill[fi].Func(mas, MAX);
      t = clock();
      Sort[si].Func(mas, MAX);
      t = clock() - t;
      if (CheckSort(mas, MAX))
        printf("%s: %10.5f \n", Fill[fi].Name, t / (double)CLOCKS_PER_SEC);
      else
        printf("            Fail\n");
    }
    /*printf("\nArray:\n");
    OutMas(mas, MAX);  */
    printf("\n");
  } 

  getchar();
}