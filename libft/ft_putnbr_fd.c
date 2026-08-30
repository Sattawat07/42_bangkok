/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:43:58 by sboontem          #+#    #+#             */
/*   Updated: 2026/08/30 20:06:19 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;
	long	divisor;
	char	c;

	if (fd < 0)
		return ;
	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	divisor = 1;
	while (number / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		c = (number / divisor) % 10 + '0';
		ft_putchar_fd(c, fd);
		divisor /= 10;
	}
}
