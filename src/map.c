/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:05:57 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/13 10:06:00 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_mapsize(int size)
{
	int		i;
	int		box;
	int		size_m;
	char	*map;

	i = 0;
	size_m = size;
	box = (size + 1) * size;
	map = (char*)ft_memalloc(box + 1);
	map[i++] = '.';
	while (i < box - 1)
	{
		if (i % size_m == 0)
		{
			size_m = size_m + size + 1;
			map[i] = '\n';
		}
		else
			map[i] = '.';
		i++;
	}
	map[i] = '\0';
	return (map);
}

char	*ft_map(char **tetriminos)
{
	int		size;
	int		map_size;
	int		k;
	char	*map;

	k = 0;
	while (tetriminos[k] != NULL)
		k++;
	size = (k - 1) * 4;
	map_size = 2;
	while (map_size * map_size < size)
		map_size++;
	map = ft_mapsize(map_size);
	while (ft_solve(map, map_size, tetriminos, 0) == 0)
	{
		free(map);
		map_size = map_size + 1;
		map = ft_mapsize(map_size);
	}
	return (map);
}
