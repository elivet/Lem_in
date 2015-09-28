/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:23:04 by elivet            #+#    #+#             */
/*   Updated: 2014/03/23 21:34:01 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

t_data	lets_start(t_data the)
{
	the.i = 0;
	the = count_move(the);
	if ((the.way = (char **)malloc(sizeof(char *) * (the.nbr * the.move))) ==\
			NULL)
		error();
	return (the);
}

void	lets_go(t_data the)
{
	int		i;

	i = 0;
	while (the.aff[i])
	{
		ft_putendl(the.aff[i]);
		i++;
	}
	ft_putchar('\n');
	i = 0;
	while (the.way[i])
	{
		ft_putendl(the.way[i]);
		i++;
	}
}

t_data	count_move(t_data the)
{
	int		i;

	i = 0;
	while (the.link[i])
		i++;
	the.move = i;
	return (the);
}

t_data	journey(t_data the)
{
	char	*tmp;

	the = lets_start(the);
	while (the.ant[the.i])
	{
		the.j = 0;
		while (the.j < the.move)
		{
			tmp = join(the.ant[the.i], the.link[the.j]);
			if (the.way[the.j + the.i] != NULL)
			{
				the.way[the.j + the.i] = joinch(the.way[the.j + the.i], ' ');
				the.way[the.j + the.i] = join(the.way[the.j + the.i], tmp);
			}
			else if (the.way[the.j + the.i] == NULL)
				the.way[the.j + the.i] = ft_strdup(tmp);
			the.j++;
		}
		the.i++;
	}
	if (the.nbr == 1)
		the.way[the.move] = NULL;
	lets_go(the);
	return (the);
}
