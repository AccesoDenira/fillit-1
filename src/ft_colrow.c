/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:28:45 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/12 16:28:47 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_rowsize(char *t)
{
	int i;
	int row_max;

	row_max = 0;
	i = 0;
	while (i < 19)
	{
		if (t[i] == '#')
		{
			row_max = row_max + 1;
			while (t[i] != '\n')
				i++;
		}
		i++;
	}
	return (row_max);
}

int		ft_colsize(char *t)
{
	int i;
	int x;
	int y;
	int col_max;

	x = 1;
	col_max = 0;
	while (x < 5)
	{
		y = 1;
		while (y < 5)
		{
			i = ft_xytoi(x, y, 4);
			if (t[i] == '#')
			{
				col_max++;
				break ;
			}
			y++;
		}
		if (col_max == 4)
			break ;
		x++;
	}
	return (col_max);
}
