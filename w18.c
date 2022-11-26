   /*********************************************
    * Id: blan5568
    * Dan Blanchette
    * 
    * This program calculates the max clique for an undirected graph
    * CREDIT: Help from Taylor Martin on this algorithm
    *********************************************/
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #include <math.h>

   int find_clique(int size, int mat[][size], int row, int clique[], int total);
   int calc_max_clique(int size, int mat[][size]);

   //main
   int main(int argc, char *argv[])
   {
      int size = atoi(argv[1]);
      int mat[size][size];
      int i, j, k, count;

      j = 0;
      for (k = 0; k < size - 1; k++)
      {
         count = 0;
         for (i = k + 1; i < size; i++)
         {
            mat[k][i] = atoi(argv[2 + j + count]);
            count++;
         }
         j += count;
      }

      for (i = 0; i < size; i++)
      {
         for (j = 0; j < i + 1; j++)
         {
            mat[i][j] = 0;
         }
      }

      for (i = 0; i < size; i++)
      {
         for (j = 0; j < size; j++)
         {
            mat[j][i] = mat[i][j];
         }
      }

      for (i = 0; i < size; i++)
      {
         for (j = 0; j < size; j++)
         {
            printf("%d ", mat[i][j]);
         }
         printf("\n");
      }

      int result = calc_max_clique(size, mat);

      for (i = size; i > 0; i--)
      {
         if (result < i)
         {
            printf("No clique found of size %d\n", i);
         }
         if (result == i)
         {
            printf("Clique found of size %d\n", i);
         }
      }

      return 0;
   }


   // find clique from adjacency matrix
   int find_clique(int size, int matrix[][size], int row, int clique[], int total)
   {
      int i;
      int count = 0;

      for (i = 0; i < size; i++)
      {
         if (clique[i] == 1 && matrix[row][i] == 1)
         {
            count++;
         }
      }
      if (count == total)
      {
         return 1;
      }
      return 0;
   }

   // return max clique
   int calc_max_clique(int size, int matrix[][size])
   {
      int i, j, k, l, count, maxClique;
      int clique[size];
      maxClique = 2;
      count = 1;
      for (l = 0; l < size; l++)
      {
         for (j = 0; j < size; j++)
         {
            clique[j] = 0;
         }
         clique[l] = 1;
         for (i = 0; i < size; i++)
         {
            k = 0;

            if (matrix[l][i] == 1)
            {
               k = find_clique(size, matrix, i, clique, count);
            }

            if (k == 1)
            {
               count++;
               clique[i] = 1;
            }
         }

         if (count > maxClique)
         {
            maxClique = count;
         }
         count = 1;
      }
      return maxClique;
   }