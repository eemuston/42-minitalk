/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:13:36 by eemuston          #+#    #+#             */
/*   Updated: 2022/11/02 14:26:40 by eemuston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	index;

	if (!(str))
		return ;
	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar_fd(str[index], fd);
			index++;
	}
}
