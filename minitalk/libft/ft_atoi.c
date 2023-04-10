/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:32:40 by eemuston          #+#    #+#             */
/*   Updated: 2022/11/10 09:49:37 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	long_result(int s)
{
	if (s == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *n)
{
	unsigned long long	r;
	int					s;
	int					i;

	r = 0;
	s = 1;
	i = 0;
	while ((n[0] >= 9 && n[0] <= 13) || n[0] == 32)
		n++;
	if (n[0] == 45)
		s *= -1;
	if (n[0] == 45 || n[0] == 43)
		n++;
	while (n[0] == '0')
		n++;
	while (n[i] >= 48 && n[i] <= 57 && n[i] != '\0')
	{
		r = r * 10 + n[i++] - 48;
	}
	if (i > 19 || r >= 9223372036854775808ULL)
		return (long_result(s));
	return (r * s);
}
