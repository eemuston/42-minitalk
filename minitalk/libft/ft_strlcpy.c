/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:33:18 by eemuston          #+#    #+#             */
/*   Updated: 2022/10/31 14:19:06 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = ft_strlen(src);
	if (n == 0)
		return (i);
	while (*src != '\0' && n > 1)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = '\0';
	return (i);
}
