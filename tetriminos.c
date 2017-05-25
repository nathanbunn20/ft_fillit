/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:21:05 by nbunn             #+#    #+#             */
/*   Updated: 2016/11/29 22:39:42 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**newtetriminos(char *tets, int tet_count)
{
	int		x;
	int		y;
	int		i;
	char	**newtets;

	x = 0;
	y = 0;
	i = 0;
	newtets = (char**)malloc(sizeof(char*) * tet_count + 1);
	while (x < tet_count)
	{
		newtets[x] = (char*)malloc(sizeof(char) * 19 + 1);
		while (y < 19)
		{
			if (tets[i] == '\n' && tets[i + 1] == '\n')
				i = i + 2;
			newtets[x][y++] = tets[i++];
		}
		newtets[x][y] = '\0';
		y = 0;
		x++;
	}
	newtets[x] = 0;
	return (newtets);
}

int		validations(char *grid)
{
	if (grid == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!(valgrch(grid)) || !(valpts(grid)) || !(numtet(grid)) ||
		!(compare(grid)))
	{
		ft_putstr("error\n");
		return (0);
	}
	else
		return (1);
}

int		checkifvalid(char *grid)
{
	int		count_newlines;

	count_newlines = 1;
	if (ft_linelen(grid) != 4)
		return (0);
	if (*grid == '\n')
		return (1);
	while (*grid != '\0')
	{
		if (*grid == '\n' && *(grid + 1) != '\n' && *(grid + 1) != '\0')
		{
			if (ft_linelen(grid + 1) != 4)
				return (0);
			count_newlines++;
		}
		else if (*grid == '\n' && (*(grid + 1) == '\n' || *(grid + 1) == '\0'))
		{
			if (count_newlines == 4)
				count_newlines = 0;
			else
				return (0);
		}
		grid++;
	}
	return (1);
}
