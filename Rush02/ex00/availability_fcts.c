/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   availability_fcts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 04:03:07 by nmorales          #+#    #+#             */
/*   Updated: 2018/07/01 21:18:52 by nmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_2(int sudoku[][9], int xline, int ycol, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (i != xline)
		{
			if (sudoku[i][ycol] == num)
				return (0);
		}
		if (i != ycol)
		{
			if (sudoku[xline][i] == num)
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_square(int sudoku[][9], int xline, int ycol, int num)
{
	int c;
	int r;
	int rstart;
	int cstart;

	rstart = (xline / 3) * 3;
	cstart = (ycol / 3) * 3;
	r = 0;
	while (r < 3)
	{
		c = 0;
		while (c < 3)
		{
			if ((rstart + r) != xline && ycol != (cstart + c))
			{
				if (sudoku[rstart + r][cstart + c] == num)
					return (0);
			}
			c++;
		}
		r++;
	}
	return (1);
}

int		available(int sudoku[][9], int xline, int ycol, int num)
{
	if (!(check_2(sudoku, xline, ycol, num)))
		return (0);
	if (!(check_square(sudoku, xline, ycol, num)))
		return (0);
	return (1);
}
