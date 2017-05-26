/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 20:46:29 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/08 20:46:31 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../includes/libft/libft.h"
# include <fcntl.h>

char	*ft_readinp(char *s);
int		ft_size(char *file);
int		ft_counttetr(char *tetr_str);
char	**ft_tetriminos(char *s);
char	**ft_buildtetr(char *s, char **ss, int i, int k);
int		ft_checkcolrow(char **tetrimonos, int k);
int		ft_checkhash(char **tetrimonos, int k, unsigned int i);
int		ft_hash(int *h, int n);
int		ft_validation(char **tetriminos);
int		ft_itoy(int i);
int		ft_xytoi(int x, int y, int size);
char	*ft_mapsize(int size);
int		ft_colsize(char *t);
int		ft_rowsize(char *t);
void	ft_asigning(char *t, char c, char *map, int i);
int		ft_fits(char *t, char c, char *map, int i);
void	ft_reasigning(char *t, char c, char *map, int i);
int		ft_solve(char *map, int map_size, char **t, int k);
char	*ft_map(char **tetriminos);
int		ft_mapstart(char *t, int x);
int		ft_countchar(char *s, int i);
void	ft_buildnewar(char **t, char **t_n, int k);
char	**ft_little_opt(char **t);
void	ft_help(char *t, char *t_n, int a, char c);

#endif
