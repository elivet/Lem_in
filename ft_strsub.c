/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 12:13:57 by elivet            #+#    #+#             */
/*   Updated: 2014/02/12 15:16:36 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "lemin.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = ft_strnew(len);
	while (i < len)
	{
		s2[i] = s[start];
		start++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
