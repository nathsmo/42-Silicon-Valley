#include <unistd.h>

void ft_putchar(char c);

void ft_replaceletter(int i, char letter, int col, char letter2)
{
      if (i == 1 || i == col)
            ft_putchar(letter);
          else
            ft_putchar(letter2);
}

void ft_addingfunction(int col, char letter, char letter2)
{
  int i;
  
  i = 1;
  while (i <= col)
  {
    ft_replaceletter(i, letter, col, letter2);
    i++;
  }
}

void ft_createrow(int indicator, int col)
{
    int i;

    i = 1;
    if (indicator == 0)
    {
      ft_addingfunction(col, 'A', 'B');
    }
    if (indicator == 2)
    {
      ft_addingfunction(col, 'C', 'B');
    }
    if (indicator == 1)
    {
      ft_addingfunction(col, 'B', ' ');
    }
    if (indicator != 2)
        ft_putchar('\n');
}

void rush02(int col, int row)
{
    int i;

    i = 1;
    while (i <= row)
        if (i == 1)
        {
            ft_createrow(0, col);
            i++;
        }
        else if (i == row)
        {
            ft_createrow(2, col);
            i++;
        }
        else if (i != 1 || i != row)
        {
            ft_createrow(1, col);
            i++;
        }
}

int main(void)
{
  rush02(4,4);
  return 0;
}
