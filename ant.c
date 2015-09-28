/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:11:53 by elivet            #+#    #+#             */
/*   Updated: 2014/03/23 15:27:00 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

char		*add_ant(int i)
{
	char	*ant;

	ant = ft_strdup("L");
	ant = join(ant, ft_itoa(i + 1));
	ant = joinch(ant, '-');
	return (ant);
}

t_data		take_ants(t_data the)
{
	int		i;

	if ((the.ant = (char **)malloc(sizeof(char *) * (the.nbr) + 1)) == NULL)
		error();
	i = 0;
	while (i < the.nbr)
	{
		the.ant[i] = add_ant(i);
		i++;
	}
	the.ant[i] = NULL;
	return (the);
}
