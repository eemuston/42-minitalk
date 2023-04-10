/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:57:34 by eemuston          #+#    #+#             */
/*   Updated: 2023/02/23 11:52:56 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	error_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	while (argv[1][i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
		{
		write(2, "Error\n", 6);
		return (-1);
		}
		i++;
	}
	return (0);
}

void	send_string_len(int pid, int len)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		len = len >> 1;
		i++;
		usleep(100);
	}
}

void	send_string_bits(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (error_check(argc, argv) == -1)
		return (-1);
	i = 0;
	pid = ft_atoi(argv[1]);
	send_string_len(pid, ft_strlen(argv[2]));
	while (argv[2][i] != '\0')
	{
		send_string_bits(pid, argv[2][i]);
		i++;
	}
	return (0);
}
