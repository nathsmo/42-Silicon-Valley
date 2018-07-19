/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:03:53 by nmorales          #+#    #+#             */
/*   Updated: 2018/07/01 21:18:55 by nmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		check_2(int sudoku[][9], int xline, int ycol, int num);
int		check_square(int sudoku[][9], int xline, int ycol, int num);
int		available(int sudoku[][9], int xline, int ycol, int num);
void	ft_print(int sudoku[][9]);
int		input_verifier(int sudoku[][9]);
int		ft_inputnbr(int sudoku[][9], char **argv);
int		ft_length_c(char **argv);

int		empty_spc(int sudoku[][9], int *xline, int *ycol)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (sudoku[i][j] == 0)
			{
				*xline = i;
				*ycol = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		solver(int sudoku[][9])
{
	int xline;
	int ycol;
	int guess;

	xline = 0;
	ycol = 0;
	if (empty_spc(sudoku, &xline, &ycol) == 0)
		return (1);
	guess = 1;
	while (guess <= 9)
	{
		if (available(sudoku, xline, ycol, guess))
		{
			sudoku[xline][ycol] = guess;
			if (solver(sudoku) == 1)
				return (1);
			sudoku[xline][ycol] = 0;
		}
		guess++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int sudoku[9][9];

	if (argc != 10)
	{
		write(1, "Error\n\0", 6);
		return (0);
	}
	if (ft_length_c(argv) == 1)
	{
		write(1, "Error\n\0", 6);
		return (0);
	}
	if (ft_inputnbr(sudoku, argv) == 0)
	{
		write(1, "Error\n\0", 6);
		return (0);
	}
	if (input_verifier(sudoku))
		if (solver(sudoku) == 0)
			return (0);
		else
			ft_print(sudoku);
	else
		write(1, "Error\n\0", 6);
	return (0);
}
