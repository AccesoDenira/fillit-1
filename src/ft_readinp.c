/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readinp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:12:49 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/10 10:12:51 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_size(char *file)
{
	int		i;
	int		fd;
	char	buf;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &buf, 1) != '\0')
	{
		if (buf != '.' && buf != '#' && buf != '\n')
			return (-1);
		i++;
	}
	close(fd);
	if (i > 545)
		return (-1);
	return (i);
}

char	*ft_readinp(char *file)
{
	int		fd;
	int		i;
	char	buf;
	char	*tetr_str;

	i = 0;
	if (ft_size(file) < 0)
		return (NULL);
	tetr_str = (char*)ft_memalloc(ft_size(file) + 1);
	if (tetr_str == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (read(fd, &buf, 1) != '\0')
	{
		if (!(buf == '.' || buf == '#' || buf == '\n'))
			return (NULL);
		tetr_str[i++] = buf;
	}
	tetr_str[i] = '\0';
	close(fd);
	if (tetr_str[0] != '.' && tetr_str[0] != '#')
		return (NULL);
	return (tetr_str);
}
