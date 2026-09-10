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
	char	c;
	long	divisor;
	long	number;

	number = n;
	divisor = 1;
	if (number < 0)
	{
		ft_putchr('-', count);
		number *= (-1);
	}
	while (number / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		c = (number / divisor) % 10 + '0';
		ft_putchr(c, count);
		divisor /= 10; 
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	
}
