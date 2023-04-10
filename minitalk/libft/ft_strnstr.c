/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:30:21 by eemuston          #+#    #+#             */
/*   Updated: 2022/11/08 14:10:22 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*str, const char *find, size_t len)
{
	int	i;
	int	k;

	i = 0;
	if (find[0] == '\0')
		return ((char *)str);
	if (len == 0)
		return (0);
	while (str[i] != '\0' && len > 0 + ft_strlen(find) - 1)
	{
		k = 0;
		while (str[i + k] != '\0' && str[i + k] == find[k])
		{	
			if (find[k + 1] == '\0')
				return ((char *)&str[i]);
			k++;
		}
		i++;
		len--;
	}
	return (0);
}
