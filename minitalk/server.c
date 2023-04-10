/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:02:43 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/23 11:58:11 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_len;

void	ft_putnbr_n_newline(int i)
{
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
}

void	print_and_free_string(char *storage, int sign)
{
	storage[g_len] = '\0';
	ft_putendl_fd(storage, 1);
	if (sign == 1)
	{
		free(storage);
		g_len = 0;
	}
}

void	get_str_len(int signal)
{
	static int	len;
	static int	bit;

	if (signal == SIGUSR1)
		len = len | 0x01 << bit;
	bit++;
	if (bit == 32)
	{
		g_len = len;
		len = 0;
		bit = 0;
	}
}

//Static int array f[3] means: f[0] = sign, f[1] = bit and f[2] = index
void	build_and_print_char_from_bits(int signal)
{
	static unsigned int	c;
	static int			f[3];
	static char			*storage;

	if (f[0] == 0)
		storage = malloc(sizeof(char) * g_len + 1);
	if (!storage)
		exit(1);
	f[0] = 1;
	if (signal == SIGUSR1)
		c = c | 0x01 << f[1];
	f[1]++;
	if (f[1] == 8)
	{
		storage[f[2]] = c;
		c = 0;
		f[1] = 0;
		f[2]++;
		if (f[2] == g_len)
		{
			print_and_free_string(storage, f[0]);
			f[2] = 0;
			f[0] = 0;
		}
	}
}

int	main(void)
{
	ft_putnbr_n_newline(getpid());
	while (1)
	{
		if (g_len == 0)
		{
			signal(SIGUSR2, get_str_len);
			signal(SIGUSR1, get_str_len);
		}
		else
		{
			signal(SIGUSR2, build_and_print_char_from_bits);
			signal(SIGUSR1, build_and_print_char_from_bits);
		}
		pause();
	}
	return (0);
}
