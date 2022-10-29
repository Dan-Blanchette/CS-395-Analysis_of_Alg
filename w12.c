/*********************************************
 * Id: blan5568
 *
 * This program will compare sorting algorithms
 * for quick sort, insertion sort, and selection sort
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>

// Prototypes
void CompareSorts(int *A, int arrSize, char sortType);
int HoaresPartition(int *A, int k, int j);
void InsertionSort(int *A, int arrSize);
void PopulateRandArr(int *A, int arrSize);
void PrintArr(int *A, int arrSize);
void QuickSort(int *A, int start, int end);
void SelectionSort(int *A, int arrSize);
void Swap(int *a, int *b);

// main driver
int main()
{
   int SIZE = 0;
   // create an array with size of elements 10^2
   SIZE = pow(10, 2);
   int Arr_1[SIZE];

   // run comparisons
   CompareSorts(Arr_1, SIZE, 's');
   CompareSorts(Arr_1, SIZE, 'i');
   CompareSorts(Arr_1, SIZE, 'q');

   // create an array with size of elements 10 ^ 3
   SIZE = pow(10, 3);
   int Arr_2[SIZE];

   // re-run comparisons
   CompareSorts(Arr_2, SIZE, 's');
   CompareSorts(Arr_2, SIZE, 'i');
   CompareSorts(Arr_2, SIZE, 'q');

   // create an array with size of elements 10 ^ 4
   SIZE = pow(10, 4);
   int Arr_3[SIZE];

   // re-run comparisons under new parameters
   CompareSorts(Arr_3, SIZE, 's');
   CompareSorts(Arr_3, SIZE, 'i');
   CompareSorts(Arr_3, SIZE, 'q');

   return 0;
}

/*Functions*/

// evaluates time differences between sorts
void CompareSorts(int *A, int arrSize, char sortType)
{
   struct timeval begin, end;
   PopulateRandArr(A, arrSize);

   if (sortType == 's')
   {
      gettimeofday(&begin, NULL);
      // call selection sort
      SelectionSort(A, arrSize);
      gettimeofday(&end, NULL);
      double runTime = ((double)(end.tv_sec - begin.tv_sec) * 1000 + (double)(end.tv_usec - begin.tv_usec) / 1000);
      printf("Number of Elements: %d Selection Sort Time[milli-seconds]: %f\n", arrSize, runTime);
   }

   if (sortType == 'i')
   {
      gettimeofday(&begin, NULL);
      // call insertion sort
      InsertionSort(A, arrSize);
      gettimeofday(&end, NULL);
      double runTime = ((double)(end.tv_sec - begin.tv_sec) * 1000 + (double)(end.tv_usec - begin.tv_usec) / 1000);
      printf("Number of Elements: %d Insertion Sort Time[milli-seconds]: %f\n", arrSize, runTime);
   }

   if (sortType == 'q')
   {
      gettimeofday(&begin, NULL);
      // call quick sort
      QuickSort(A, 0, arrSize);
      gettimeofday(&end, NULL);
      double runTime = ((double)(end.tv_sec - begin.tv_sec) * 1000 + (double)(end.tv_usec - begin.tv_usec) / 1000);
      printf("Number of Elements: %d Quick Sort Time[milli-seconds]: %f\n\n", arrSize, runTime);
   }
}

// Hoare's partitioning
int HoaresPartition(int *A, int low_index, int high_index)
{
   int x = A[low_index], i = (low_index - 1), j = high_index;
   while (1)
   {
      do
      {
         j--;
      } while (A[j] > x);

      do
      {
         i++;
      } while (A[i] < x);

      if (i < j)
      {
         Swap(&A[i], &A[j]);
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
   int i, j, srtKey;

   for (i = 1; i < arrSize; i++)
   {
      srtKey = A[i];
      j = i - 1;

      // for the elements in array[0,..,i-1] greater than the sortKey,
      // insert them ahead of the srtKey position
      while (j >= 0 && A[j] > srtKey)
      {
         A[j + 1] = A[j];
         j = j - 1;
      }
      A[j + 1] = srtKey;
   }
}

// adds random numbers between 0 and 10
void PopulateRandArr(int *A, int arrSize)
{
   srand(time(NULL));
   int i;
   for (i = 0; i < arrSize; i++)
   {
      int updatedValue = rand() % 10;
      A[i] = updatedValue;
   }
}

// helper function that prints array elements
void PrintArr(int *A, int arrSize)
{
   int i;
   for (i = 1; i < arrSize; i++)
   {
      printf("%d ", A[i]);
   }
   printf("\n");
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
// helper function swaps array elements
void Swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                    100|            0.01 |           0.006|       0.005|
//|                   1000|            1.36 |            0.70|       0.063|
//|                  10000|            88.56|           51.00|        0.58|
//+-----------------------+-----------------+----------------+------------+

//RAW OUTPUT
//Number of Elements: 100 Selection Sort Time[milli-seconds]: 0.010000
//Number of Elements: 100 Insertion Sort Time[milli-seconds]: 0.006000
//Number of Elements: 100 Quick Sort Time[milli-seconds]: 0.005000

//Number of Elements: 1000 Selection Sort Time[milli-seconds]: 1.357000
//Number of Elements: 1000 Insertion Sort Time[milli-seconds]: 0.698000
//Number of Elements: 1000 Quick Sort Time[milli-seconds]: 0.063000

//Number of Elements: 10000 Selection Sort Time[milli-seconds]: 88.560000
//Number of Elements: 10000 Insertion Sort Time[milli-seconds]: 51.001000
//Number of Elements: 10000 Quick Sort Time[milli-seconds]: 0.580000