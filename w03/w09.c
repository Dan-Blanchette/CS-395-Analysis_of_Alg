/*********************************************
 * Id: blan5568
 *
 * This program will perform selection sort on a
 * data set.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *array, int size);

void printArr(int *arr, int size);

int main(int argc, char *argv[])
{
   int convArgs[argc];
   int i;

   for(i = 1; i < argc; i++)
   {
      convArgs[i - 1] = atoi(argv[i]);
   }

   // print
   printArr(convArgs, argc);
   printf("\n");
   selectionSort(convArgs, argc);
   printArr(convArgs, argc);
   printf("\n");
   return 0;
}
// This function sorts an array of data. It looks at the first element
// of an array and makes comparisons based on the lowest value encountered.
// once found, the elements are swapped and the process starts again.
void selectionSort(int *array, int size)
{
   int i, j, minIndex;

   for(i = 0; i < (size - 2); i++)
   {
      minIndex = i;
      for( j = i; j < size - 1; j++)
      {
         if (array[j] < array[minIndex])
         {
            minIndex = j;
            // printf("%d ", array[j]);
         }
      }
      if(minIndex != i)
      {
         /* intialize a temporary pointer to store the element position for swapping*/
         int temp = array[minIndex];
         /* move the index to the element whose value is less than the
         selected element.*/
         array[minIndex] = array[i];
         // Swap elements with the selected element.
         array[i] = temp;
      }
      printArr(array, size);
      printf("\n");
   }
}
// simple print function
void printArr(int *arr, int size)
{
   int i;

   for(i = 0; i < size - 1; i++)
   {
      printf("%d ", arr[i]);
   }
}