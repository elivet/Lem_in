/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nospace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 17:43:11 by elivet            #+#    #+#             */
/*   Updated: 2013/12/02 19:09:21 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		ft_nospace(char c)
{
	if (c == '\n' || c == '\t' || c == ' ' || c == '\v' || c == '\r' ||\
			c == '\f')
		return (1);
	return (0);
}
