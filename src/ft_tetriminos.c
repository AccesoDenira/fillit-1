/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:11:19 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/09 14:11:20 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_countchar(char *s, int i)
{
	int d;

	d = 1;
	while (s[i] != '\0')
	{
		i++;
		d++;
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
			break ;
	}
	return (d);
}

int		ft_counttetr(char *tetr_str)
{
	int num;
	int i;

	i = 0;
	num = 0;
	while (tetr_str[i])
	{
		if (tetr_str[i] != '\n' || tetr_str[i + 1] != '\n')
		{
			i = i + ft_countchar(tetr_str, i) - 2;
			if (tetr_str[i + 1] == '\0' && tetr_str[i - 1] == '\n')
				return (-1);
			if (tetr_str[i] == '\n' && tetr_str[i + 1] == '\0')
				return (num);
			num++;
		}
		i++;
	}
	return (num);
}

char	**ft_buildtetr(char *s, char **ss, int i, int k)
{
	int j;
	int d;
	int n;

	d = ft_counttetr(s);
	if (d < 1 || d > 26)
		return (NULL);
	while (k < d)
	{
		j = 0;
		if (!(s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] == '\n'))
		{
			n = ft_countchar(s, i);
			ss[k] = (char*)ft_memalloc(n + 1);
			while (n-- > 1)
				ss[k][j++] = s[i++];
			ss[k][j++] = '\n';
			ss[k][j] = '\0';
			k++;
		}
		i = i + 2;
	}
	ss[k] = NULL;
	return (ss);
}

char	**ft_tetriminos(char *s)
{
	char	*tetr_str;
	char	**tetriminos;
	int		i;

	tetr_str = ft_readinp(s);
	if (tetr_str == NULL)
		return (NULL);
	if (tetr_str[0] == '\0')
		return (NULL);
	i = ft_counttetr(tetr_str);
	tetriminos = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	if (tetriminos == NULL)
		return (NULL);
	tetriminos = ft_buildtetr(tetr_str, tetriminos, 0, 0);
	if (tetriminos == NULL)
		return (NULL);
	free(tetr_str);
	return (tetriminos);
}
