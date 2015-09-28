/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 20:26:57 by elivet            #+#    #+#             */
/*   Updated: 2014/03/23 20:28:14 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

int			ft_checkn(char *line);
char		*ft_exceeding(char *line, int start, size_t len);
int			ft_errors(char *line, char *temp, int ret);
char		*ft_cpyline(char *s1);

int			ft_checkn(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_exceeding(char *line, int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	s2 = ft_strnew(len);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = line[j + i];
		i++;
	}
	line[start - 1] = '\0';
	return (s2);
}

int			ft_errors(char *line, char *temp, int ret)
{
	if (line == NULL)
		return (-1);
	if (temp == NULL)
		return (-1);
	if (ret == -1)
		return (-1);
	return (1);
}

char		*ft_cpyline(char *s1)
{
	char	*dest;
	int		i;

	i = ft_strlen(s1);
	dest = ft_strnew(i);
	ft_strcpy(dest, s1);
	free(s1);
	return (dest);
}

int			get_next_line(int const fd, char **line)
{
	static char		*temp = NULL;
	char			*buffer;
	int				i;
	int				ret;

	buffer = ft_strnew(BUFF_SIZE + 1);
	if (temp == NULL)
		*line = ft_strnew(BUFF_SIZE);
	else
	{
		free(*line);
		*line = ft_cpyline(temp);
	}
	while ((i = ft_checkn(*line)) < 0)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[ret] = '\0';
		temp = join(*line, buffer);
		*line = ft_cpyline(temp);
		if (ret == 0)
			return (0);
	}
	free(buffer);
	temp = ft_exceeding(*line, i + 1, ft_strlen(*line) - i);
	return (ft_errors(*line, temp, ret));
}
