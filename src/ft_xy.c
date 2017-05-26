/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:23:40 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/13 10:23:42 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_itoy(int i)
{
	int y;

	if (i < 5)
		y = 1;
	else if (i < 10 && i >= 5)
		y = 2;
	else if (i < 15 && i >= 10)
		y = 3;
	else
		y = 4;
	return (y);
}

int		ft_xytoi(int x, int y, int size)
{
	int i;

	i = y * size + y + x - 2 - size;
	return (i);
}
