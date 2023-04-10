/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:07:17 by eemuston          #+#    #+#             */
/*   Updated: 2022/11/09 13:30:55 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	chr;
	int		i;

	if (s[0] == '\0' && !s)
		return (0);
	i = ft_strlen(s);
	ptr = (char *)s + i;
	chr = (char)c;
	while (i >= 0)
	{
		if (*ptr == chr)
			return (ptr);
		ptr--;
		i--;
	}
	return (0);
}
