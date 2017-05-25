/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:41:27 by nbunn             #+#    #+#             */
/*   Updated: 2016/12/07 17:28:08 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			print_grid(char **grid)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (grid[x] != 0)
	{
		ft_putstr(grid[x]);
		write(1, "\n", 1);
		x++;
	}
}

void			placetetrimino(char **grid, int xy, char *tets, int size)
{
	t_one		dios;
	int			pieces;
	char		*temptets;

	dios.x = xy / size;
	dios.y = xy % size;
	pieces = 0;
	temptets = tets;
	while (*tets != '\0' && pieces != 4)
	{
		if (grid[dios.x][dios.y] == '\0')
			placefirst(&dios.x, &dios.y, tets, temptets);
		if (TETS(*tets) && grid[dios.x][dios.y] == '.')
		{
			grid[dios.x][dios.y] = *tets;
			pieces++;
			dios.y++;
		}
		dios = ft_dios(tets, dios);
		tets++;
	}
}

int				checkplace(char **grid, int xy, char *tets, int size)
{
	t_two		norm;

	norm.i = 0;
	norm.pieces = 0;
	while (!(TETS(tets[norm.i])))
		norm.i++;
	norm.j = norm.i;
	norm.x = xy / size;
	norm.y = xy % size;
	while (tets[norm.i] != '\0' && grid[norm.x] != 0)
	{
		norm = ft_pequeno(grid, norm, tets);
		norm = ft_cortito(tets, norm);
		if (norm.y < 0)
			return (0);
		norm.i++;
		if (norm.pieces == 4)
		{
			tets = tets + norm.j;
			placetetrimino(grid, xy, tets, size);
			return (1);
		}
	}
	return (0);
}

void			removepiece(int piece, char **grid)
{
	int			x;
	int			y;
	char		c;

	x = 0;
	c = (piece + 65);
	while (grid[x] != '\0')
	{
		y = 0;
		while (grid[x][y] != '\0')
		{
			if (grid[x][y] == c)
				grid[x][y] = '.';
			y++;
		}
		x++;
	}
}

int				solvepuzzle(char **grid, char **tets, int piece, int size)
{
	int			place;
	int			x;
	int			y;

	place = 0;
	if (tets[piece] == NULL)
		return (1);
	while (place <= (size * size))
	{
		x = place / size;
		y = place % size;
		if (checkplace(grid, place, tets[piece], size) == 1)
		{
			if (solvepuzzle(grid, tets, piece + 1, size))
				return (1);
			removepiece(piece, grid);
		}
		place++;
	}
	return (0);
}
