/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:07:02 by eemuston          #+#    #+#             */
/*   Updated: 2022/12/14 12:20:02 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_counter(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	char	*if_positive(char *s, long nb, int len)
{
	while (nb > 0)
	{
		s[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	nb;

	nb = n;
	len = nbr_counter(nb);
	s = (char *)malloc(sizeof(char) * (len) + 1);
	if (!(s))
		return (0);
	s[len--] = '\0';
	if (nb == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	if (nb < 0)
	{
		s[0] = '-';
		nb *= -1;
	}
	if (nb > 0)
		if_positive(s, nb, len);
	return (s);
}
