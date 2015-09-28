/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:19:47 by elivet            #+#    #+#             */
/*   Updated: 2014/02/21 20:20:06 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "lemin.h"

static char		*ft_negativ(int size, long int n);
static char		*ft_positiv(int size, long int n);

static char		*ft_negativ(int size, long int n)
{
	char	*str;

	str = ft_strnew(size);
	n = -n;
	while (size > 0)
	{
		str[size - 1] = (n % 10) + '0';
		size--;
		n = n / 10;
	}
	str[0] = '-';
	return (str);
}

static char		*ft_positiv(int size, long int n)
{
	char	*str;

	str = ft_strnew(size);
	while (size > 0)
	{
		str[size - 1] = (n % 10) + '0';
		size--;
		n = n / 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char		*s;
	char		*new;
	int			size;
	long int	n2;

	new = NULL;
	n2 = n;
	size = ft_sizeofint(n);
	if (n2 == 0)
	{
		if ((new = ft_strnew(1)) == NULL)
			return (NULL);
		new[0] = '0';
		new[1] = '\0';
		return (new);
	}
	if (n2 > 0)
		s = ft_positiv(size, n2);
	if (n2 < 0)
		s = ft_negativ(size, n2);
	return (s);
}
