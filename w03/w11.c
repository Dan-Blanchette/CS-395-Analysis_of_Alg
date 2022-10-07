/*********************************************
 * Id: blan5568
 *
 * This program will perform selection sort on a
 * data set.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int size);

void printArr(int *arr, int size);

int main(int argc, char *argv[])
{
   int intArr[argc];
   int i;
   // convert array data from ascii to integer
   for(i = 0; i < argc - 1; i++)
   {
      intArr[i - 1] = atoi(argv[i]);
   }
   // print unsorted array
   printArr(intArr, argc);
   printf("\n");
   // sort the data
   insertionSort(intArr, argc);
   // print results
   printArr(intArr, argc);
   printf("\n");

   return 0;
}

/* This function will perform insertion sort.
 The array is partitioned and the element to the left is
 compared with the other elements to the right side of the partition
 once a value is found to be less than the partition, the value is inserted
 and the remaining values are moved to the right of the swapped value.
*/
void insertionSort(int *arr, int size)
{
   int i, j, v;

   for(i = 0; i < size -1; i++)
   {
      v = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > v)
      {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j +1] = v;
   }
   printArr(arr, size);
}

void printArr(int *arr, int size)
{
   int i;

   for(i = 0; i < size - 1; i++)
   {
      printf("%d ", arr[i]);
   }
}