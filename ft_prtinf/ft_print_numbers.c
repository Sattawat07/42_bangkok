/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 21:44:47 by sboontem          #+#    #+#             */
/*   Updated: 2026/09/09 21:44:47 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long	number;
	char	buffer[10];
	int		i;

	number = n;
	if (number == 0)
	{
		ft_putchr('0', count);
		return ;
	}
	if (number < 0)
	{
		ft_putchr('-', count);
		number = -number;
	}
	i = 0;
	while (number > 0)
	{
		buffer[i++] = (number % 10) + '0';
		number /= 10;
	}
	while (i > 0)
		ft_putchr(buffer[--i], count);
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	char	buffer[10];
	int		i;

	i = 0;
	if (n == 0)
	{
		ft_putchr('0', count);
		return ;
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		ft_putchr(buffer[--i], count);
}
