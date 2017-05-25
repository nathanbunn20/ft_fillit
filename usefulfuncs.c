/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefulfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:17:23 by nbunn             #+#    #+#             */
/*   Updated: 2016/12/21 17:00:49 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

size_t	ft_linelen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

int		gettetcount(char *tets)
{
	int i;
	int tet_count;

	i = 0;
	tet_count = 1;
	while (tets[i] != '\0')
	{
		if (tets[i] == '\n' && (tets[i + 1] == '\n'))
			tet_count++;
		i++;
	}
	return (tet_count);
}

char	**finalgrid(int i)
{
	char	**grid;
	int		y;
	int		x;

	x = 0;
	y = 0;
	grid = (char**)malloc(sizeof(char*) * i + 1);
	while (x < i)
	{
		grid[x] = (char*)malloc(sizeof(char) * i + 1);
		while (y < i)
		{
			grid[x][y] = '.';
			y++;
		}
		grid[x][y] = '\0';
		y = 0;
		x++;
	}
	grid[x] = 0;
	return (grid);
}

int		finalgridsize(char *grid, int x)
{
	int		i;
	int		piece_count;
	int		size;
//	int		n;
//
	i = 0;
	piece_count = 1;
	size = 2;
	while (grid[i] != '\0')
	{
		if (grid[i] == '\n' && grid[i + 1] == '\n')
			piece_count++;
		i++;
	}
//	n = (piece_count * 4);
//	while (size * size < n)
//		size++;
//	int size;

	size = 1;
	size = size + x;
	return (size);
}
