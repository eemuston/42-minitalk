/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:27:05 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/16 11:46:46 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static int	ft_free(const char **split, size_t	j)
{
	while (split[j--])
		free((void *)split[j]);
	free(split);
	exit(1);
	return (0);
}

static	char	*temp_str(const char **split, const char *s, int *f)
{
	char	*temp;
	int		i;
	int		start;
	int		finish;
	int		j;

	i = 0;
	start = f[2];
	finish = f[0];
	j = f[1];
	temp = (char *)malloc(sizeof(char) * (finish - start + 2));
	if (!temp)
		ft_free(split, j);
	while (start < finish)
		temp[i++] = s[start++];
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(const char *s, char c)
{
	int		f[3];
	char	**split;

	if (!s)
		return (0);
	split = (char **)malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!split)
		return (0);
	f[0] = 0;
	f[1] = 0;
	f[2] = -1;
	while (f[0] <= (int)ft_strlen(s))
	{
		if (s[f[0]] != c && f[2] < 0)
			f[2] = f[0];
		else if ((s[f[0]] == c || f[0] == (int)ft_strlen(s)) && f[2] >= 0)
		{
			split[f[1]++] = temp_str((const char **)split, s, f);
			f[2] = -1;
		}
		f[0]++;
	}
	split[f[1]] = 0;
	return (split);
}
