/*********************************************
 * Id: blan5568
 * Dan Blanchette
 * 
 * This program uses the coin collecting roboth algorithm
 * CREDIT: Help from Taylor Martin on this algorithm
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

void init_board(char* argv[], int rows, int cols, char board[rows][cols]);
void show_board(int rows, int cols, char board[rows][cols]); 
void print_optimal_path(int rows, int cols, int optBoard[rows][cols]);
void coin_collecting_robot(int rows, int cols, char board[cols][rows], int optBoard[rows][cols]); 
int find_max(int numOne, int numTwo);

int main(int argc, char *argv[])
{
   if(argc < 3)
   {
      printf("Error not enough arguments entered.");
      return -1;
   }

   int rows = atoi(argv[1]);
   int cols = atoi(argv[2]);

   if((argc - 3) < (rows * cols))
   {
      printf("Error: not enough arguments entered");
      return -1;
   }

   char board[rows][cols];
   int optBoard[rows][cols];

   init_board(argv, rows, cols, board); 
   show_board(rows, cols, board);
   coin_collecting_robot(rows, cols, board, optBoard);
   print_optimal_path(rows, cols, optBoard);

   return 0;
}

//initializes the initial starting board 
void init_board(char* argv[], int rows, int cols, char board[rows][cols])
{
   int cellCount = 3;
   int i, j;

   for(i = 0; i < rows; ++i)
   {
      for(j = 0; j < cols; ++j)
      {
         board[i][j] = *argv[cellCount++];
      }
   }
}

//coin collecting robot algorithm
void coin_collecting_robot(int rows, int cols, char board[rows][cols], int optBoard[rows][cols])
{
   int i, j;
   const int charConversion = 48;
   int xPos = 0;
   optBoard[0][0] = board[0][0] - charConversion;

   for (j = 1; j < cols; ++j)
   {
      if ((board[0][j] != 'X') && (xPos == 0))
      {
         optBoard[0][j] = optBoard[0][j - 1] + (board[0][j] - charConversion);
      }
      else
      {
         optBoard[0][j] = 0;
         board[0][j] = 'X';
         xPos = 1;
      }
   }

   xPos = 0;

   for (i = 1; i < rows; ++i)
   {
      if ((board[i][0] != 'X') && (xPos == 0))
      {
         optBoard[i][0] = optBoard[i - 1][0] + (board[i][0] - charConversion);
      }
      else
      {
         optBoard[i][0] = 0;
         board[i][0] = 'X';
         xPos = 1;
      }
      for (j = 1; j < cols; ++j)
      {
         if ((board[i - 1][j] == 'X') && (board[i][j - 1] == 'X'))
         {
            board[i][j] = 'X';
         }
         if ((j != cols - 1) && (board[i + 1][j] == 'X') && (board[i][j + 1] == 'X'))
         {
            board[i][j] = 'X';
         }
         if (board[i][j] != 'X')
         {
            optBoard[i][j] = find_max(optBoard[i - 1][j] + (board[i][j] - charConversion), optBoard[i][j - 1] + (board[i][j] - charConversion));
         }
         else
         {
            optBoard[i][j] = 0;
         }
      }
   }
}

//prints optimal path for robot to travel
void print_optimal_path(int rows, int cols, int optBoard[rows][cols])
{
   int i, j;

   printf("Coin Collecting Table:\n");

   for(i = 0; i < rows; ++i)
   {
      for(j = 0; j < cols; ++j)
      {
         printf("%d\t", optBoard[i][j]);
      }
      printf("\n");
   }

   printf("\nThe optimal path with this board is:  %d\n", optBoard[rows - 1][cols - 1]);
}

//prints the sent in input board 
void show_board(int rows, int cols, char board[rows][cols])
{
   int i, j;

   printf("Board Input:\n");
   for (i = 0; i < rows; ++i)
   {
      for (j = 0; j < cols; ++j)
      {
         printf("%c\t", board[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

//finds the max of two sent in integers. Returns max value
int find_max(int num1, int num2)
{
   int max = 0;

   if(num1 > num2)
   {
      max =    num1;
   }
   else if (num2 > num1)
   {
      max = num2;
   }
   else
   {
      max = 0;
   }

   return max;
}