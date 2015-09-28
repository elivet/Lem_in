/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 18:52:44 by elivet            #+#    #+#             */
/*   Updated: 2014/03/23 21:33:51 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

char	*take_name(char *line)
{
	char	**tab;
	char	*ret;

	if ((tab = (char **)malloc(sizeof(char *) * 4)) == NULL)
		error();
	tab = ft_strsplit(line, ' ');
	ret = ft_strdup(tab[0]);
	free(tab);
	return (ret);
}

int		check_nbr(t_data the)
{
	int		check;
	int		i;

	i = 0;
	check = 0;
	while (the.line[i] != '\0')
	{
		if (ft_isdigit(the.line[i]) == 0)
		{
			check = 1;
			break ;
		}
		else
			i++;
	}
	if (check == 1)
		error();
	if (ft_countwords(the.line, ' ') == 1 && check == 0)
	{
		the.nbr = ft_atoi(the.line);
		return (the.nbr);
	}
	else
		return (0);
}

int		check_tube(char *line)
{
	if (ft_countwords(line, '-') == 2)
		return (1);
	return (0);
}

void	check_it(t_data the)
{
	int		i;
	char	**tab;

	i = 0;
	if (the.line[0] == 'L' || the.line[0] == '#')
		error();
	if ((tab = (char **)malloc(sizeof(char *) * 4)) == NULL)
		error();
	tab = ft_strsplit(the.line, ' ');
	while (tab[1][i] != '\0')
	{
		if (ft_isdigit(tab[1][i]) == 0)
			error();
		else
			i++;
	}
	i = 0;
	while (tab[2][i] != '\0')
	{
		if (ft_isdigit(tab[2][i]) == 0)
			error();
		else
			i++;
	}
}

int		check_room(t_data the)
{
	if (ft_countwords(the.line, ' ') == 3)
		return (1);
	return (0);
}
