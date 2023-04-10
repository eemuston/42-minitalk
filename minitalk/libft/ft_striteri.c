/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:36:55 by eemuston          #+#    #+#             */
/*   Updated: 2022/11/02 14:25:15 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	j;

	if (!s || !f)
		return ;
	j = 0;
	while (*s)
	{
		i = ft_strlen(s);
		while (j < i)
		{
			f(j, s);
			j++;
			s++;
		}
	}
}
