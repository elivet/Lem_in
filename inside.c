/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 15:13:33 by elivet            #+#    #+#             */
/*   Updated: 2014/03/23 21:12:22 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_data		ft_else(t_data the, char *tmp)
{
	the.cpy = the.list;
	the = save(tmp, the, the.top);
	the.top = 0;
	return (the);
}

t_data		first_look(t_data the)
{
	the = search(the, the.start, the.top);
	if (the.found == NULL)
		error();
	return (the);
}

t_data		not_found(t_data the, char *tmp)
{
	the.list = the.cpy;
	free(the.link);
	if ((the.link = (char **)malloc(sizeof(char *) * 1000)) == NULL)
		error();
	the = ft_delete(the, tmp);
	the.top = 1;
	the.what = 0;
	the = search(the, the.start, the.top);
	the.top = 2;
	return (the);
}

t_data		init_top(t_data the)
{
	the.top = 0;
	the.what = 0;
	the.stop = 0;
	return (the);
}

t_data		findandcheck(t_data the, char **tab, char *find)
{
	the.keep = 0;
	if (ft_strcmp(find, tab[0]) == 0 &&
			check_before(the, tab[1], the.what) == 0)
		the.found = ft_strdup(tab[1]);
	else if (ft_strcmp(find, tab[1]) == 0 &&
			check_before(the, tab[0], the.what) == 0)
		the.found = ft_strdup(tab[0]);
	else
		the.keep = 1;
	return (the);
}
