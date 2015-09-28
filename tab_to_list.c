/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:10:38 by elivet            #+#    #+#             */
/*   Updated: 2014/03/23 15:29:53 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_list		*tab_to_list(t_data the)
{
	int		i;
	t_list	*list;

	i = 0;
	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		error();
	list->content = ft_itoa(the.nbr);
	list->next = list;
	while (the.tube[i])
	{
		ft_lstaddtail(&list, the.tube[i], ft_itoa(the.nbr));
		i++;
	}
	return (list);
}
