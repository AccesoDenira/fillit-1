/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:11:56 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/10 10:11:58 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free(char **t_n)
{
	int k;

	k = 0;
	while (t_n[k] != NULL)
	{
		free(t_n[k]);
		k++;
	}
	free(t_n);
	t_n = NULL;
}

int		main(int ac, char **av)
{
	char **tetriminos;
	char **t_n;
	char *map;

	if (ac == 2)
	{
		tetriminos = ft_tetriminos(av[1]);
		if (ft_validation(tetriminos))
		{
			t_n = ft_little_opt(tetriminos);
			map = ft_map(t_n);
			ft_putstr(map);
			ft_putchar('\n');
			free(map);
			ft_free(t_n);
		}
		else
			ft_putstr("error\n");
		free(tetriminos);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
}
