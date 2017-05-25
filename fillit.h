/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbunn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:27:25 by nbunn             #+#    #+#             */
/*   Updated: 2016/12/20 21:35:04 by nbunn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE 4096
# define TETS(x) x >= 65 && x <= 90

typedef	struct		s_one
{
	int				x;
	int				y;
}					t_one;

typedef	struct		s_two
{
	int				i;
	int				x;
	int				y;
	int				j;
	int				pieces;
}					t_two;

typedef	struct		s_main
{
	char			*tetriminos;
	int				tet_count;
	int				x;
	char			**newtets;
}					t_main;

char				*getgrid(char *argv);
void				ft_putstr(char *str);
char				*convertgrid(char *grid);
size_t				ft_linelen(const char *s);
char				**finalgrid(int i);
int					finalgridsize(char *grid, int x);
int					place_piece(char **grid, int x, int y);
int					solvepuzzle(char **grid, char **tets, int piece, int size);
int					gettetcount(char *tets);
char				**newtetriminos(char *tets, int tet_count);
int					checkplace(char **grid, int xy, char *tets, int size);
void				placetetrimino(char **grid, int xy, char *tets, int size);
void				removepiece(int piece, char **grid);
void				print_grid(char **grid);
void				placefirst(int *x, int *y, char *tets, char *temptets);
void				placethird (char *tets, int *x, int *y);
t_one				ft_dios(char *tets, t_one dios);
t_two				ft_cortito(char *tets, t_two norm);
t_two				ft_pequeno(char **grid, t_two norm, char *tets);
int					validations(char *grid);
t_main				acortando (char *grid, t_main pri);
void				eugidro (t_main pri, int solved);
void				checkconnections(char *p, int contlin, int i, int *conex);
int					valgrch(char *p);
int					valpts(char *p);
int					numtet(char *p);
int					compare(char *p);
int					checkifvalid(char *grid);

#endif
