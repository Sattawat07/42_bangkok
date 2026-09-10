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
	long	divisor;

	number = n;
	if (number < 0)
	{
		ft_putchr('-', count);
		number = -number;
	}
	divisor = 1;
	while (number / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		ft_putchr((number / divisor) + '0', count);
		number %= divisor;
		divisor /= 10;
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	unsigned long	number;
	unsigned long	divisor;

	number = n;
	divisor = 1;
	while (number / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		ft_putchr((number / divisor) + '0', count);
		number %= divisor;
		divisor /= 10;
	}
}
