/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 12:35:15 by elivet            #+#    #+#             */
/*   Updated: 2014/03/23 20:16:03 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "lemin.h"

char		*join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	s3 = NULL;
	if ((s3 = (char *)malloc((ft_strlen(s1)) + (ft_strlen(s2)) + 1)) == NULL)
		error();
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

char		*joinch(char *s1, char c)
{
	char	*r;
	int		i;

	if (!s1)
		return (NULL);
	if ((r = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2))) == NULL)
		error();
	if (!r)
		return (NULL);
	i = 0;
	while (*s1)
		r[i++] = *(s1++);
	r[i++] = c;
	r[i] = '\0';
	return (r);
}

