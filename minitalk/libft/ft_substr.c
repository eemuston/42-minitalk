/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:56:47 by eemuston          #+#    #+#             */
/*   Updated: 2022/11/02 14:27:25 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	c;
	unsigned int	hs;

	if (!s)
		return (0);
	i = 0;
	c = 0;
	hs = start;
	while (hs++ < len + start && s[hs] != '\0')
		c++;
	hs = start;
	sub = (char *)malloc(sizeof(char) * c + 1);
	if (!(sub))
		return (0);
	while (start < len + hs && s[start] != '\0' && start <= ft_strlen(s))
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
