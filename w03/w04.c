/*********************************************
 * Id: blan5568
 *
 * uses gaussian elimination and will conduct
 * matrix multiplication
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
// conducts gaussian elimination
void gaussianElim(int n, float A[n][n + 1]);
// print the matrix
void printMatrix(int n, float A[n][n+1]);
int main(int argc, char *argv[])
{
   int i, n;
   int argConv[argc];
   for(i = 0; i < argc; i++)
   {
      argConv[i - 1] = atoi(argv[i]);
   }
   // n <- {Num Rows For the Matrix = Argv[0]}
   n = argConv[0];
   // intialize float matrix
   float matrix[n][n+1];
   gaussianElim(n, matrix);

   return 0;
}

// conducts gaussian elimination
// Input: An n x (n +1) matrix A[n-1], n) of real numbers
void gaussianElim(int n, float A[n][n+1])
{
   int i, j, k;
   float temp;
   for (i = 0; i < n-2; i++)
   {
      for (j = i + 1; j < n - 1; j++)
      {
         temp = A[j][i];
         for (k = i; k < n; k++)
         {
            A[j][k] = (A[j][k] - A[i][k]) * temp/A[i][i];
         }
      }
   }
}

// Print the matrix
void printMatrix(int n, float A[n][n+1])
{
   int i,j;

   for(i = 0; i < n; i++)
   {
      for (j = 0; j < n + 1; j++)
      {
         printf("%.2f", A[i][j]);
      }
      printf("\n");
   }
}