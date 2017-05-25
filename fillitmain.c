/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:36:38 by nbunn             #+#    #+#             */
/*   Updated: 2016/12/07 17:18:38 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		*grid;
	int			solved;
	t_main		pri;

	solved = 0;
	pri.x = 0;
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit target_file\n");
		return (1);
	}
	grid = getgrid(argv[1]);
	if (!(validations(grid)))
		return (1);
	pri.tetriminos = convertgrid(grid);
	pri.tet_count = gettetcount(pri.tetriminos);
	pri.newtets = newtetriminos(pri.tetriminos, pri.tet_count);
	eugidro(pri, solved);
	return (0);
}
