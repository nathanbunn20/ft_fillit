/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placevar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:48:38 by igallego          #+#    #+#             */
/*   Updated: 2016/12/07 19:48:40 by igallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		placefirst(int *x, int *y, char *tets, char *temptets)
{
	*x = *x + 1;
	*y = 0;
	*tets = *temptets;
}

t_one		ft_dios(char *tets, t_one dios)
{
	if (TETS(*tets) && (!(TETS(*(tets + 1)))) && TETS(*(tets + 3)))
	{
		tets = tets + 2;
		dios.x++;
		dios.y = dios.y - 3;
	}
	else if (TETS(*tets) && (!(TETS(*(tets + 1)))) && TETS(*(tets + 4)))
	{
		tets = tets + 3;
		dios.x++;
		dios.y = dios.y - 2;
	}
	else if (TETS(*tets) && (!(TETS(*(tets + 1)))) && TETS(*(tets + 5)))
	{
		tets = tets + 4;
		dios.x++;
		dios.y--;
	}
	return (dios);
}

t_two		ft_pequeno(char **grid, t_two norm, char *tets)
{
	if (grid[norm.x][norm.y] == '\0')
	{
		norm.y = 0;
		norm.x++;
		norm.i = norm.j;
		norm.pieces = 0;
	}
	else if (TETS(tets[norm.i]) && grid[norm.x][norm.y] == '.')
	{
		norm.pieces++;
		norm.y++;
	}
	return (norm);
}

t_two		ft_cortito(char *tets, t_two norm)
{
	if (TETS(tets[norm.i]) && (!(TETS(tets[norm.i + 1]))) &&
		TETS(tets[norm.i + 3]))
	{
		norm.i = norm.i + 2;
		norm.x++;
		norm.y = norm.y - 3;
	}
	else if (TETS(tets[norm.i]) && (!(TETS(tets[norm.i + 1]))) &&
			TETS(tets[norm.i + 4]))
	{
		norm.i = norm.i + 3;
		norm.y = norm.y - 2;
		norm.x++;
	}
	else if (TETS(tets[norm.i]) && (!(TETS(tets[norm.i + 1]))) &&
			TETS(tets[norm.i + 5]))
	{
		norm.i = norm.i + 4;
		norm.y = norm.y - 1;
		norm.x++;
	}
	return (norm);
}
