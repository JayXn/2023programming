#include <stdio.h>
#include <math.h>
#define CHESSSIZE 8

int x, y;
int color;
int chess[CHESSSIZE][CHESSSIZE];

void inputArray(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int piece;
      scanf("%d", &piece);
      chess[i][j] = piece;
    }
  }
}


void print_color(int x_cell, int y_cell)
{
  if (chess[x_cell][y_cell] == 0)
  {
    printf("空白");
  }
  else if (chess[x_cell][y_cell] == 1)
  {
    printf("黑色");
  }
  else if (chess[x_cell][y_cell] == 2)
  {
    printf("白色");
  }
}


void search_print(int x_cell, int y_cell)
{
  int x_change = x_cell;
  int y_change = y_cell;
  for(int i = -1 ; i <= 1 ; i++ ){
    for(int j = -1 ; j <= 1 ; j++){
      while(x_change < 8, x_change >= 0){
        x_change = x_change + j;
        int sum = 0;
        sum += 1;

        if(i != 0 || j == 0){
          break;
        }
        else if(chess[y_change][x_change] == 0){
          break;
        }
        else if(chess[y_change][x_change] == color && sum < 2){
          break;
        }
        else if(chess[y_change][x_change] == color && sum >= 2){
          printf("(%d,%d)能下 %d 的子\n", x_change, y_change, color);
          break;
        }
      }

      while(y_change < 8, y_change >= 0){
        y_change = y_change + i;
        int sum = 0;
        sum += 1;

        if(i == 0 || j != 0){
          break;
        }
        else if(chess[y_change][x_change] == 0){
          break;
        }
        else if(chess[y_change][x_change] == color && sum < 2){
          break;
        }
        else if(chess[y_change][x_change] == color && sum >= 2){
          printf("(%d,%d)能下 %d 的子\n", x_change, y_change, color);
          break;
        }
      }

      while(x_change < 8, x_change >= 0, y_change < 8, y_change >= 0){
        x_change = x_change + j;
        y_change = y_change + i;

        int sum = 0;
        sum += 1;

        if(i == 0 || j == 0){
          break;
        }
        else if(chess[y_change][x_change] == 0){
          break;
        }
        else if(chess[y_change][x_change] == color && sum < 2){
          break;
        }
        else if(chess[y_change][x_change] == color && sum >= 2){
          printf("(%d,%d)能下 %d 的子\n", x_change, y_change, color);
          break;
        }
      }

    }
  }
}

int main()
{
  inputArray(8);
  while (1)
  {
    scanf("%d %d", &x, &y);
    scanf("%d", &color);

    print_color(x,y);
    if (!(chess[x][y] == 0))
    {
      break;
    }

    search_print(x, y);
  }

  return 0;
}
