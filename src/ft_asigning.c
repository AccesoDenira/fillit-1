/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asigning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:28:49 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/12 14:28:51 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fits(char *t, char c, char *map, int i)
{
	int j;
	int d;
	int l;
	int map_size;

	j = -1;
	d = 0;
	l = i;
	map_size = 0;
	while (map[map_size] != '\n')
		map_size = map_size + 1;
	while (t[++j])
	{
		if (t[j] == '\n')
		{
			i = i + map_size + 1;
			d = 0;
			j = j + 1;
		}
		if (t[j] == c && map[i + d] != '.')
			return (0);
		d = d + 1;
	}
	ft_asigning(t, c, map, l);
	return (1);
}

void	ft_asigning(char *t, char c, char *map, int i)
{
	int j;
	int d;
	int map_size;

	j = -1;
	d = 0;
	map_size = 0;
	while (map[map_size] != '\n')
		map_size = map_size + 1;
	while (t[++j])
	{
		if (t[j] == '\n')
		{
			d = 0;
			j = j + 1;
			i = map_size + i + 1;
		}
		if (t[j] == c)
			map[i + d] = c;
		d = d + 1;
	}
}

void	ft_reasigning(char *t, char c, char *map, int i)
{
	int j;
	int d;
	int map_size;

	j = -1;
	d = 0;
	map_size = 0;
	while (map[map_size] != '\n')
		map_size = map_size + 1;
	while (t[++j])
	{
		if (t[j] == '\n')
		{
			i = i + map_size + 1;
			d = 0;
			j = j + 1;
		}
		if (t[j] == c)
			map[i + d] = '.';
		d = d + 1;
	}
}

int		ft_solve(char *map, int map_size, char **t, int k)
{
	int x;
	int y;
	int i;

	x = 1;
	y = 1;
	while (y <= map_size)
	{
		i = ft_xytoi(x, y, map_size);
		if (ft_fits(t[k], 'A' + k, map, i))
		{
			if (t[k + 1] == NULL || ft_solve(map, map_size, t, k + 1) != 0)
				return (1);
			else
				ft_reasigning(t[k], 'A' + k, map, i);
		}
		if (x == map_size)
		{
			x = 0;
			y = y + 1;
		}
		x = x + 1;
	}
	return (0);
}
