/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:12:54 by elivet            #+#    #+#             */
/*   Updated: 2014/03/23 19:30:24 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

int		main(void)
{
	t_data	the;

	the.start = NULL;
	the.end = NULL;
	the = information(the);
	the.list = tab_to_list(the);
	if (the.start == NULL || the.end == NULL)
		error();
	the = ft_link(the);
	journey(the);
	free(the.link);
	return (0);
}
