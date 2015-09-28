/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 18:55:15 by elivet            #+#    #+#             */
/*   Updated: 2014/03/02 18:29:28 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

void		ft_lstaddtail(t_list **list, char *content, char *start)
{
	t_list		*new;
	t_list		*tmp;

	new = ft_lstnew(content);
	if (!*list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	new->next = tmp;
	while (ft_strcmp(start, tmp->next->content) != 0)
		tmp = tmp->next;
	tmp->next = new;
}
