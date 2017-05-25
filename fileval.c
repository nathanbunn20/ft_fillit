/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igallego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 23:27:35 by igallego          #+#    #+#             */
/*   Updated: 2016/12/20 20:54:15 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_grch(int *i, int *contlin, int *contchar)
{
	*i = 0;
	*contlin = 0;
	*contchar = 0;
}

int			valgrch(char *p)
{
	int		i;
	int		contlin;
	int		contchar;

	init_grch(&i, &contlin, &contchar);
	while (p[i] != '\0')
	{
		if (p[i] == '.' || p[i] == '#')
			contchar++;
		else if (p[i] == '\n')
			contlin++;
		if (contchar == 16)
		{
			if (p[i + 1] == '\0')
				return (0);
			if (contlin != 3)
				return (0);
			contlin = -2;
			contchar = 0;
		}
		i++;
	}
	if (contchar != 0)
		return (0);
	return (contlin == -1 ? (1) : (0));
}

int			valpts(char *p)
{
	int		i;
	int		contgat;
	int		contlin;

	i = 0;
	contgat = 0;
	contlin = 0;
	while (p[i] != '\0')
	{
		if (p[i] == '#')
			contgat++;
		if (p[i] == '\n')
			contlin++;
		if (contlin == 4)
		{
			if (contgat != 4)
				return (0);
			contlin = -1;
			contgat = 0;
		}
		i++;
	}
	return (1);
}

int			numtet(char *p)
{
	int		i;
	int		contlin;
	int		numtetra;

	i = 0;
	contlin = 0;
	numtetra = 0;
	while (p[i] != '\0')
	{
		if (p[i] == '\n')
			contlin++;
		if (p[i] != '.' && p[i] != '#' && p[i] != '\n')
			return (0);
		if (contlin == 4)
		{
			numtetra++;
			contlin = -1;
		}
		i++;
	}
	return (numtetra > 26 ? 0 : numtetra);
}

int			compare(char *p)
{
	int		i;
	int		contlin;
	int		conex;

	i = 0;
	contlin = 0;
	conex = 0;
	while (p[i] != '\0')
	{
		if (p[i] == '\n')
			contlin++;
		if (p[i] == '#')
			checkconnections(p, contlin, i, &conex);
		if (contlin == 4)
		{
			if (conex != 6 && conex != 8)
				return (0);
			contlin = -1;
			conex = 0;
		}
		i++;
	}
	if (checkifvalid(p) == 0)
		return (0);
	return (1);
}
