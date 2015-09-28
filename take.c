/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 18:41:55 by elivet            #+#    #+#             */
/*   Updated: 2014/03/23 20:15:08 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_data		first_take(t_data the)
{
	the.i = 0;
	the.j = 0;
	if ((the.aff = (char **)malloc(sizeof(char *) * 10000)) == NULL)
		error();
	get_next_line(0, &the.line);
	the.nbr = check_nbr(the);
	the = take_ants(the);
	if ((the.tube = (char **)malloc(sizeof(char *) * (the.nbr * 1000 + 1))) ==\
			NULL)
		error();
	the.aff[0] = ft_strdup(the.line);
	return (the);
}

t_data		take_start(t_data the)
{
	if (ft_strcmp(the.line, "##start") == 0)
	{
		get_next_line(0, &the.line);
		if (the.line[0] == '#')
			error();
		the.j++;
		the.aff[the.j] = ft_strdup(the.line);
		if (check_room(the) == 1)
			the.start = take_name(the.line);
		else
			error();
	}
	return (the);
}

t_data		take_end(t_data the)
{
	if (ft_strcmp(the.line, "##end") == 0)
	{
		get_next_line(0, &the.line);
		if (the.line[0] == '#')
			error();
		the.j++;
		the.aff[the.j] = ft_strdup(the.line);
		if (check_room(the) == 1)
			the.end = take_name(the.line);
		else
			error();
	}
	return (the);
}

t_data		finish(t_data the, int i, int j)
{
	if ((the.link = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
		error();
	the.tube[i] = NULL;
	j++;
	the.aff[j] = NULL;
	return (the);
}

t_data		information(t_data the)
{
	the = first_take(the);
	if (the.nbr == 0)
		error();
	while (get_next_line(0, &the.line))
	{
		if (the.line[0] == '\0')
			error();
		the.j++;
		the.aff[the.j] = ft_strdup(the.line);
		if (check_tube(the.line) == 1)
		{
			the.tube[the.i] = ft_strdup(the.line);
			the.i++;
		}
		the = take_start(the);
		if (check_room(the) == 1)
			check_it(the);
		the = take_end(the);
	}
	the = finish(the, the.i, the.j);
	return (the);
}
