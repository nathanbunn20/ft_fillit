/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlefiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:00:30 by nbunn             #+#    #+#             */
/*   Updated: 2016/12/07 00:29:31 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*getgrid(char *argv)
{
	int		fd;
	char	*grid;
	int		ret;

	grid = (char*)malloc(sizeof(char) * BUF_SIZE + 1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, grid, 4096);
	grid[ret] = '\0';
	if (close(fd) == -1)
		return (NULL);
	return (grid);
}

static void	initializevariables(unsigned char *i, int *j, int *z, int *g)
{
	*i = 'A';
	*j = 0;
	*z = 0;
	*g = 1;
}

char		*convertgrid(char *grid)
{
	unsigned char	i;
	int				j;
	int				z;
	int				g;

	initializevariables(&i, &j, &z, &g);
	while (grid[j] != '\0')
	{
		if (grid[j] == '#')
			grid[j] = i;
		if (grid[j] == '\n')
		{
			z++;
			if ((z / 5) == g)
			{
				i = i + 1;
				g++;
			}
		}
		if (i == 91)
			return (NULL);
		j++;
	}
	return (grid);
}

void		eugidro(t_main pri, int solved)
{
	char	**nfinalgrid;
	int		finalgridsizen;

	while (solved == 0)
	{
		finalgridsizen = finalgridsize(pri.tetriminos, pri.x);
		nfinalgrid = finalgrid(finalgridsizen);
		if (solvepuzzle(nfinalgrid, pri.newtets, 0, finalgridsizen) == 1)
			solved = 1;
		if (solved == 1)
			print_grid(nfinalgrid);
		free(nfinalgrid);
		pri.x++;
	}
}

void		checkconnections(char *p, int contlin, int i, int *conex)
{
	if (p[i + 1] == '#')
		*conex = *conex + 1;
	if (contlin != 3)
		if (p[i + 5] == '#')
			*conex = *conex + 1;
	if (contlin != 0)
		if (p[i - 5] == '#')
			*conex = *conex + 1;
	if (p[i - 1] == '#')
		*conex = *conex + 1;
}
