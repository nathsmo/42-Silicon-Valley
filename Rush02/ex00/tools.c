/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:08:22 by nmorales          #+#    #+#             */
/*   Updated: 2018/07/01 21:18:58 by nmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		available(int sudoku[][9], int xline, int ycol, int num);

void	ft_print(int sudoku[][9])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			c = (sudoku[i][j] + '0');
			write(1, &c, 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n\0", 1);
		i++;
	}
}

int		input_verifier(int sudoku[][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (sudoku[i][j] != 0)
			{
				if (!(available(sudoku, i, j, sudoku[i][j])))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_inputnbr(int sudoku[][9], char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if ((argv[i + 1][j] > 57 || argv[i + 1][j] < 48)
					&& argv[i + 1][j] != '.')
				return (0);
			else if (argv[i + 1][j] == 46)
				sudoku[i][j] = 0;
			else
				sudoku[i][j] = (argv[i + 1][j] - 48);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_length_c(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			j++;
		if (j != 9)
			return (1);
		i++;
	}
	if (i != 10)
		return (1);
	return (0);
}
