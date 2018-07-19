#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_replaceletter(int i, char letter, int col, char letter2)
{
      if (i == 1 || i == col)
            ft_putchar(letter);
          else
            ft_putchar(letter2);
}

void ft_createrow(int indicator, int col)
{
    int i;

    i = 1;
    if (indicator == 0)
    {
        while (i <= col)
        {
            ft_replaceletter(i, 'A', col, 'B');
            i++;
        }
    }
    if (indicator == 2)
    {
        while (i <= col)
        {
            ft_replaceletter(i, 'C', col, 'B');
            i++;
        }
    }
    else
    {
        while (i <= col)
        {
            ft_replaceletter(i, 'B', col, ' ');
            ++i;
        }
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
