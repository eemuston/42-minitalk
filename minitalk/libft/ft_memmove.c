/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:58:58 by eemuston          #+#    #+#             */
/*   Updated: 2022/11/01 07:56:53 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*hdest;
	const char		*hsrc;

	hdest = (char *)dest;
	hsrc = (const char *)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	if (hsrc < hdest)
	{
		while (n-- > 0)
			(hdest[n]) = (hsrc[n]);
	}
	else
	{
		while (i < n)
		{
			(hdest[i]) = (hsrc[i]);
			i++;
		}
	}
	return (dest);
}
