/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:06:20 by eemuston          #+#    #+#             */
/*   Updated: 2022/11/09 15:52:59 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_front(char const *s1, char const *set)
{
	size_t	f;
	size_t	c;

	f = 0;
	c = 0;
	while (set[f] != '\0' && s1[c] != '\0')
	{
		if (s1[c] == set[f])
		{
			c++;
			f = -1;
		}
		f++;
	}
	return (c);
}

static size_t	check_back(char const *s1, char const *set)
{
	size_t	f;
	size_t	i;

	f = 0;
	i = ft_strlen(s1);
	while (set[f] != '\0' && i != 0)
	{
		if (s1[i - 1] == set[f])
		{
			i--;
			f = -1;
		}
		f++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	char			*copy;
	int				j;
	int				c;
	int				f;

	if (!s1)
		return (0);
	c = check_front(s1, set);
	i = check_back(s1, set);
	if (c > i)
		f = 0;
	else
		f = i - c + 1;
	j = 0;
	copy = (char *)malloc(sizeof(char) * (f));
	if (!(copy))
		return (0);
	while (c < i)
		copy[j++] = s1[c++];
	copy[j] = '\0';
	return (copy);
}
