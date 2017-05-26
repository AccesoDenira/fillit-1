/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:32:27 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/18 12:32:29 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int g_a;
int g_b;
int g_i;
int g_j;

int		ft_mapstart(char *t, int x)
{
	int y;
	int i;

	while (x < 5)
	{
		y = 1;
		while (y < 5)
		{
			i = ft_xytoi(x, y, 4);
			if (t[i] == '#')
				break ;
			y++;
		}
		if (t[i] == '#')
			break ;
		x++;
	}
	i = 0;
	while (t[i] != '#')
		i++;
	y = ft_itoy(i);
	i = ft_xytoi(x, y, 4);
	return (i);
}

void	ft_help(char *t, char *t_n, int a, char c)
{
	int d;
	int b;

	g_i = ft_mapstart(t, 1);
	g_j = 0;
	b = ft_rowsize(t);
	while (b-- > 0)
	{
		d = 0;
		while (d < a)
		{
			if (t[g_i + d] == '#')
				t_n[g_j++] = c;
			else
				t_n[g_j++] = '.';
			d = d + 1;
		}
		if (b > 0)
			t_n[g_j++] = '\n';
		g_i = g_i + 5;
	}
	t_n[g_j] = '\0';
}

void	ft_buildnewar(char **t, char **t_n, int k)
{
	int a;
	int b;

	if (k >= 0)
	{
		a = ft_colsize(t[k]);
		b = ft_rowsize(t[k]);
		t_n[k] = (char*)ft_memalloc((a + 1) * b);
		ft_help(t[k], t_n[k], a, 'A' + k);
		free(t[k]);
		ft_buildnewar(t, t_n, k - 1);
	}
}

char	**ft_little_opt(char **t)
{
	char	**t_n;
	int		k;

	k = 0;
	while (t[k] != NULL)
		k++;
	t_n = (char**)ft_memalloc(sizeof(char*) * (k + 1));
	t_n[k] = NULL;
	free(t[k]);
	k = k - 1;
	ft_buildnewar(t, t_n, k);
	return (t_n);
}
