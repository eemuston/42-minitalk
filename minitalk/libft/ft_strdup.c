/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:56:24 by eemuston          #+#    #+#             */
/*   Updated: 2022/11/08 10:49:38 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (!(dup))
		return (0);
	while (*s)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}
