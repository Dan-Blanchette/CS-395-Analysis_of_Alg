/*********************************************
 * Id: blan5568
 *
 * This program uses the Hoare's partition method
 * for the quicksort algorithm
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

// Prototypes
void CompareSorts(int *A, int arrSize, char sortType);
int HoaresPartition(int *A, int k, int j);
void InsertionSort(int *A, int arrSize);
void PopuateRandArr(int *A, int arrSize);
void PrintArr(int *A, int arrSize);
void QuickSort(int *A, int start, int end);
void SelectionSort(int *A, int arrSize);
void Swap(int *a, int *b);

// main driver
int main()
{
   // create an array with total elements 10^2
   int SIZE = pow(10, 2);
   int Arr1[SIZE];

   // run comparisons
   CompareSorts(Arr1, SIZE, 'selct');
   CompareSorts(Arr1, SIZE, 'insert');
   CompareSorts(Arr1, SIZE, 'quick');

   // create an array with total elements 10 ^ 3
   int SIZE = pow(10, 3);
   int Arr1[SIZE];

   // run comparisons
   CompareSorts(Arr1, SIZE, 'selct');
   CompareSorts(Arr1, SIZE, 'insert');
   CompareSorts(Arr1, SIZE, 'quick');

   // create an array with total elements 10 ^ 4
   int SIZE = pow(10, 4);
   int Arr1[SIZE];

   // run comparisons
   CompareSorts(Arr1, SIZE, 'selct');
   CompareSorts(Arr1, SIZE, 'insert');
   CompareSorts(Arr1, SIZE, 'quick');

   return 0;
}

/*Functions*/

// evaluates time differences between sorts
void CompareSorts(int *A, int arrSize, char sortType)
{

}

// Hoare's partitioning
int HoaresPartition(int *A, int low_index, int high_index)
{
   int x = A[low_index], i = (low_index - 1), j = high_index;
   while(1)
   {
      do
      {
         j--;
      } 
      while (A[low_index] > x);

      do
      {
         i++;
      } 
      while (A[i] < x);

      if ( i < j)
      {
         swap(&A[i], &A[j]);
      }
      else
      {
         return j + 1;
      }
   }
}

// insertion sort function
void InsertionSort(int *A, int arrSize)
{

}

// adds random numbers between 0 and 10
void PopulateRandArr(int *A, int arrSize)
{

}

// helper function that prints array elements
void PrintArr(int *A, int arrSize)
{

}

// Quick Sort Function
void QuickSort(int *A, int low, int high)
{
   int part;

   if (high - low < 2)
   {
      return;
   }

   part = HoaresPartition(A, low, high);
   QuickSort(A, low, part);
   QuickSort(A, part, high);
}

// selection sort algorithm
void SelectionSort(int *A, int arrSize)
{
   int i, j, minIndex;

   for (i = 0; i < (arrSize - 2); i++)
   {
      minIndex = i;
      for (j = i; j < arrSize - 1; j++)
      {
         if (A[j] < A[minIndex])
         {
            minIndex = j;
            // printf("%d ", array[j]);
         }
      }
      if (minIndex != i)
      {
         /* intialize a temporary pointer to store the element position for swapping*/
         int temp = A[minIndex];
         /* move the index to the element whose value is less than the
         selected element.*/
         A[minIndex] = A[i];
         // Swap elements with the selected element.
         A[i] = temp;
      }
   }
}

void Swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}
