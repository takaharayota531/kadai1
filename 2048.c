#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

int is_outside(int x, int y, int width, int height)
{
  return x < 0 || x >= width || y < 0 || y >= height;
}
int print_boarda(int a)
{
  if (a == 0)
  {
    a = 2;
  }
  else if (a == 1)
  {
    a = 5;
  }
  else if (a == 2)
  {
    a = 8;
  }
  else
  {
    a = 11;
  }
  return a;
}
int print_boardb(int b)
{
  if (b == 0)
  {
    b = 2;
  }
  else if (b == 1)
  {
    b = 7;
  }
  else if (b == 2)
  {
    b = 11;
  }
  else
  {
    b = 17;
  }
  return b;
}
void praise_words(int a)
{
  if (a == 0)
  {
    printf("いいよその調子！！\r\n");
  }
  if (a == 1)
  {
    printf("やっぱりね、パズルができる男子がモテるんですよ\r\n");
  }
  else if (a == 2)
  {
    printf("やっぱりねー東大生たるものできて当然ですよねえ\r\n");
  }
  else if (a == 3)
  {
    printf("がんばれ\r\n");
  }
  else
  {
    printf("勝つのじゃ\r\n");
  }
}

int main(int argc, char *argv[])
{

  int deadcount = 0;
  int const height = 14;
  int const width = 20;
  int board[height][width];
  system("/bin/stty raw onlcr");

  int g = 0;
  g = getchar();
  if (g == 'q')
  {
    for (int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
      {
        if (y == 2 || y == 5 || y == 8 || y == 11)
        {
          if (x == 2 || x == 7 || x == 12 || x == 17)
          {
            if (x == 2 && y == 2)
            {
              board[y][x] = 2;
            }
            else
            {
              board[y][x] = '-';
            }
          }
          else
          {
            board[y][x] = 0;
          }
        }
        else
        {
          board[y][x] = 0;
        }
      }
    }
  }

  else if (g == 'w')
  {
    for (int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
      {
        if (y == 2 || y == 5 || y == 8 || y == 11)
        {
          if (x == 2 || x == 7 || x == 12 || x == 17)
          {
            if (x == 2 && y == 2)
            {
              board[y][x] = 2;
            }
            else if (x == 7 && y == 5)
            {
              board[y][x] = 'x';
            }
            else if (x == 12 && y == 11)
            {
              board[y][x] = 'x';
            }
            else if (x == 17 && y == 2)
            {
              board[y][x] = 'x';
            }

            else
            {
              board[y][x] = '-';
            }
          }
          else
          {
            board[y][x] = 0;
          }
        }
        else
        {
          board[y][x] = 0;
        }
      }
    }
  }
  FILE *fp = stdout;

  int x = 0;
  int y = 0;
  system("/bin/stty raw onlcr");
  for (int c = 0; c != '.'; c = getchar())
  {

    if (c == 'j')
    {

      for (int x = 0; x < width; x++)
      {
        for (int y = 0; y < height; y++)
        {
          if (board[y][x] == 0 || board[y][x] == 'x')
          {
            continue;
          }

          if (is_outside(x - 5, y, width, height))
            continue;
          if (board[y][x - 5] == '-')
          {
            board[y][x - 5] = board[y][x];
            board[y][x] = '-';
            if (is_outside(x - 10, y, width, height))
              continue;
            if (board[y][x - 10] == '-')
            {
              board[y][x - 10] = board[y][x - 5];
              board[y][x - 5] = '-';
              if (is_outside(x - 15, y, width, height))
                continue;
              if (board[y][x - 15] == '-')
              {
                board[y][x - 15] = board[y][x - 10];
                board[y][x - 10] = '-';
              }
              else if (board[y][x - 15] == board[y][x - 10])
              {
                board[y][x - 15] = board[y][x - 10] + board[y][x - 15];
                board[y][x - 10] = '-';
              }
            }
            else if (board[y][x - 10] == board[y][x - 5])
            {
              board[y][x - 10] = board[y][x - 5] + board[y][x - 10];
              board[y][x - 5] = '-';
            }
          }
          else
          {
            if (board[y][x - 5] == board[y][x])
            {
              board[y][x - 5] = board[y][x] + board[y][x - 5];
              board[y][x] = '-';
            }
          }
        }
      }
    }
    else if (c == 'm')
    {
      for (int y = height; 0 <= y; y--)
      {
        for (int x = 0; x < width; x++)
        {
          if (board[y][x] == 0 || board[y][x] == 'x')
          {
            continue;
          }
          if (is_outside(x, y + 3, width, height))
            continue;
          if (board[y + 3][x] == '-')
          {
            board[y + 3][x] = board[y][x];
            board[y][x] = '-';
            if (is_outside(x, y + 6, width, height))
              continue;
            if (board[y + 6][x] == '-')
            {
              board[y + 6][x] = board[y + 3][x];
              board[y + 3][x] = '-';
              if (is_outside(x, y + 9, width, height))
                continue;
              if (board[y + 9][x] == '-')
              {
                board[y + 9][x] = board[y + 6][x];
                board[y + 6][x] = '-';
              }
              else if (board[y + 9][x] == board[y + 6][x])
              {
                board[y + 9][x] = board[y + 6][x] + board[y + 9][x];
                board[y][x + 6] = '-';
              }
            }
            else if (board[y + 6][x] == board[y + 3][x])
            {
              board[y + 6][x] = board[y + 3][x] + board[y + 6][x];
              board[y + 3][x] = '-';
            }
          }
          else
          {
            if (board[y + 3][x] == board[y][x])
            {
              board[y + 3][x] = board[y][x] + board[y][x];
              board[y][x] = '-';
            }
          }
        }
      }
    }
    else if (c == 'l')
    {
      for (int x = width; 0 <= x; x--)
      {
        for (int y = 0; y < height; y++)
        {
          if (board[y][x] == 0 || board[y][x] == 'x')
          {
            continue;
          }
          if (is_outside(x + 5, y, width, height))
            continue;
          if (board[y][x + 5] == '-')
          {
            board[y][x + 5] = board[y][x];
            board[y][x] = '-';
            if (is_outside(x + 10, y, width, height))
              continue;
            if (board[y][x + 10] == '-')
            {
              board[y][x + 10] = board[y][x + 5];
              board[y][x + 5] = '-';
              if (is_outside(x + 15, y, width, height))
                continue;
              if (board[y][x + 15] == '-')
              {
                board[y][x + 15] = board[y][x + 10];
                board[y][x + 10] = '-';
              }
              else if (board[y][x + 15] == board[y][x + 10])
              {
                board[y][x + 15] = board[y][x + 10] + board[y][x + 15];
                board[y][x + 10] = '-';
              }
            }

            else if (board[y][x + 10] == board[y][x + 5])
            {
              board[y][x + 10] = board[y][x + 5] + board[y][x + 10];
              board[y][x + 5] = '-';
            }
          }
          else
          {
            if (board[y][x + 5] == board[y][x])
            {
              board[y][x + 5] = board[y][x] + board[y][x + 5];
              board[y][x] = '-';
            }
          }
        }
      }
    }

    else if (c == 'i')
    {
      for (int y = 0; y < height; y++)
      {
        for (int x = 0; x < width; x++)
        {
          if (board[y][x] == 0 || board[y][x] == 'x')
          {
            continue;
          }
          if (is_outside(x, y - 3, width, height))
            continue;
          if (board[y - 3][x] == '-')
          {
            board[y - 3][x] = board[y][x];
            board[y][x] = '-';
            if (is_outside(x, y - 6, width, height))
              continue;
            if (board[y - 6][x] == '-')
            {
              board[y - 6][x] = board[y - 3][x];
              board[y - 3][x] = '-';
              if (is_outside(x, y - 9, width, height))
                continue;
              if (board[y - 9][x] == '-')
              {
                board[y - 9][x] = board[y - 6][x];
                board[y - 6][x] = '-';
              }

              else if (board[y - 9][x] == board[y - 6][x])
              {
                board[y - 9][x] = board[y - 6][x] + board[y - 9][x];
                board[y - 6][x] = '-';
              }
            }

            else if (board[y - 6][x] == board[y - 3][x])
            {
              board[y - 6][x] = board[y - 3][x] + board[y - 6][x];
              board[y - 3][x] = '-';
            }
          }

          else
          {
            if (board[y - 3][x] == board[y][x])
            {
              board[y - 3][x] = board[y][x] + board[y][x];
              board[y][x] = '-';
            }
          }
        }
      }
    }

    for (int q = 0; q < 50; q++)
    {

      int a = rand() % 4;
      int b = rand() % 4;
      int k1 = print_boarda(a);
      int k2 = print_boardb(b);

      if (board[k1][k2] == '-')
      {
        int k = rand() % 2;

        if (k == 1)
        {
          board[k1][k2] = 4;

          break;
        }
        else if (k == 0)
        {
          board[k1][k2] = 2;

          break;
        }
      }
    }

    system("clear");

    fprintf(fp, "press '.' to stop\r\n");
    fprintf(fp, "+");
    for (int k = 0; k < width; k++)
      fprintf(fp, "=");
    fprintf(fp, "+\r\n");

    for (int y = 0; y < height; y++)
    {
      fprintf(fp, "|");
      for (int x = 0; x < width; x++)
      {

        if (board[y][x] == 2)
        {
          fprintf(fp, "\e[31m2\e[0m");
        }
        else if (board[y][x] == 4)
        {
          fprintf(fp, "\e[33m4\e[0m");
        }
        else if (board[y][x] == 8)
        {
          fprintf(fp, "\e[32m8\e[0m");
        }
        else if (board[y][x] == 0)
        {
          fprintf(fp, " ");
        }
        else if (board[y][x] == 16)
        {
          fprintf(fp, "\e[36m16\e[0m");
          x++;
        }
        else if (board[y][x] == 32)
        {
          fprintf(fp, "\e[36m32\e[0m");
          x++;
        }
        else if (board[y][x] == 64)
        {
          fprintf(fp, "\e[36m64\e[0m");
          x++;
        }
        else if (board[y][x] == 128)
        {
          fprintf(fp, "\e[36m128\e[0m");
          x += 2;
        }
        else if (board[y][x] == 256)
        {
          fprintf(fp, "\e[36m256\e[0m");
          x += 2;
        }
        else if (board[y][x] == 512)
        {
          fprintf(fp, "\e[36m512\e[0m");
          x += 2;
        }
        else if (board[y][x] == 1024)
        {
          fprintf(fp, "\e[36m1024\e[0m");
          x += 3;
        }
        else if (board[y][x] == 2048)
        {
          fprintf(fp, "\e[36m2048\e[0m");
          x += 3;
        }
        else if (board[y][x] == '-')
        {
          fprintf(fp, "-");
        }
        else if (board[y][x] == 'x')
        {
          fprintf(fp, "x");
        }
      }
      fprintf(fp, "|\r\n");
    }

    fprintf(fp, "+");
    for (int k = 0; k < width; k++)
      fprintf(fp, "=");
    fprintf(fp, "+\r\n");
    fprintf(fp, "l: →　m:↓ j:←　i:↑\r\n");

    if (board[2][2] == 16 || board[2][2] == 32 || board[2][2] == 64 || board[2][2] == 128 || board[2][2] == 256 || board[2][2] == 512 || board[2][2] == 1024 || board[2][2] == 2048)
    {
      deadcount++;
    }
    if (board[11][2] == 16 || board[11][2] == 32 || board[11][2] == 64 || board[11][2] == 128 || board[11][2] == 256 || board[11][2] == 512 || board[11][2] == 1024 || board[11][2] == 2048)
    {
      deadcount++;
    }
    if (board[2][17] == 16 || board[2][17] == 32 || board[2][17] == 64 || board[2][17] == 128 || board[2][17] == 256 || board[2][17] == 512 || board[2][17] == 1024 || board[2][17] == 2048)
    {
      deadcount++;
    }
    if (board[11][17] == 16 || board[11][17] == 32 || board[11][17] == 64 || board[11][17] == 128 || board[11][17] == 256 || board[11][17] == 512 || board[11][17] == 1024 || board[11][17] == 2048)
    {
      deadcount++;
    }
    fprintf(fp, "deadcount :");
    printf("%d\r\n", deadcount);
    if (deadcount > 10)
    {
      printf("The game is over!!!!!!!!!!!!!!!\r\nYou are too stupid to win the game!!!!!!!!!!!\r\n");
    }
    fprintf(fp, "Level");
    if (g = 'q', g = getchar())
    {
      fprintf(fp, "1\r\n");
    }
    else if (g = 'w', g = getchar())
    {
      fprintf(fp, "2\r\n");
    }
    int count = 0;
    for (int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
      {
        if (board[y][x] == '-')
        {
          count++;

          if (count == 16)
          {
            printf("The game is over!!!!!!!!!!!!!!!\r\nYou are too stupid to win the game!!!!!!!!!!!\r\n");
          }
        }
      }
    }

    int c = rand() % 5;
    praise_words(c);

    for (int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
      {
        if (board[y][x] == 2048)
        {
          printf("Game Clear!!!!!!!!!!!\r\nCongratulation!!!!!!!!!!!!\r\n松井先生の授業とても好きでしたありがとうございます!!!!!!!!");
        }
      }
    }

    fflush(fp);
  }
  system("/bin/stty cooked");
  return EXIT_SUCCESS;
}