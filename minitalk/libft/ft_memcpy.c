/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:43:44 by eemuston          #+#    #+#             */
/*   Updated: 2022/11/14 11:14:23 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*hdest;
	const char	*hsrc;

	hdest = (char *)dest;
	hsrc = (const char *)src;
	if (hdest == 0 && hsrc == 0)
		return (dest);
	while (n--)
	{
		*(hdest++) = (*hsrc);
		hsrc++;
	}
	return (dest);
}
