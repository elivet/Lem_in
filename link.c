/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:51:37 by elivet            #+#    #+#             */
/*   Updated: 2014/03/23 20:15:48 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

int			check_before(t_data the, char *str, int what)
{
	int		i;

	i = 0;
	if (!(the.link[i]) && ft_strcmp(the.start, str) == 0 && what == 1)
		return (1);
	while (the.link[i])
	{
		if (ft_strcmp(the.link[i], str) == 0 || ft_strcmp(the.start, str) == 0)
			return (1);
		i++;
	}
	return (0);
}

t_data		save(char *found, t_data the, int top)
{
	static int	i = 0;

	if (top == 2)
		i = 0;
	the.link[i] = ft_strdup(found);
	i++;
	return (the);
}

t_data		ft_delete(t_data the, char *del)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		error();
	new->content = ft_itoa(the.nbr);
	new->next = new;
	if (ft_strcmp(the.start, del) == 0 || ft_strcmp(the.end, del) == 0)
		error();
	if (the.list->content == NULL)
		error();
	while (ft_strcmp(the.list->content, ft_itoa(the.nbr)) != 0)
		the.list = the.list->next;
	the.list = the.list->next;
	while (ft_strcmp(the.list->content, ft_itoa(the.nbr)) != 0)
	{
		if (ft_strequ(the.list->content, the.cpy->content) != 1)
			ft_lstaddtail(&new, the.list->content, ft_itoa(the.nbr));
		the.list = the.list->next;
	}
	the.list = new;
	return (the);
}

t_data		search(t_data the, char *find, int top)
{
	char		**tab;
	static int	turn = 0;

	the.list = the.list->next;
	if (top == 1)
		turn = 0;
	while (turn < 4)
	{
		if (ft_strcmp(the.list->content, ft_itoa(the.nbr)) == 0)
		{
			the.list = the.list->next;
			turn++;
		}
		tab = ft_strsplit(the.list->content, '-');
		the = findandcheck(the, tab, find);
		if (the.keep == 0)
			return (the);
		the.list = the.list->next;
	}
	the.found = NULL;
	return (the);
}

t_data		ft_link(t_data the)
{
	char	*tmp;

	the = init_top(the);
	the = first_look(the);
	while (ft_strcmp(the.found, the.end) != 0)
	{
		the.what = 1;
		the.stop++;
		if (the.stop > 100000)
			error();
		tmp = ft_strdup(the.found);
		the = search(the, the.found, the.top);
		if (the.found == NULL)
		{
			the = not_found(the, tmp);
			if (the.found == NULL)
				return (the);
		}
		else
			the = ft_else(the, tmp);
	}
	if (ft_strcmp(the.found, the.end) == 0)
		the = save(the.found, the, the.top);
	return (the);
}
