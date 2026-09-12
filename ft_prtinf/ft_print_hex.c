/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 21:45:32 by sboontem          #+#    #+#             */
/*   Updated: 2026/09/09 21:45:32 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int num, char specifier, int *count)
{
	char			*base;
	unsigned long	number;
	unsigned long	divisor;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else if (specifier == 'X')
		base = "0123456789ABCDEF";
	number = num;
	divisor = 1;
	while (number / divisor >= 16)
		divisor *= 16;
	while (divisor > 0)
	{
		ft_putchr(base[number / divisor], count);
		number %= divisor;
		divisor /= 16;
	}
}

void	ft_putptr(void *ptr, int *count)
{
	char			*base;
	unsigned long	address;
	unsigned long	divisor;

	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	base = "0123456789abcdf";
	address = (unsigned long)ptr;
	divisor = 1;
	while (address / divisor >= 16)
		divisor *= 16;
	while (divisor > 0)
	{
		ft_putchr(base[address / divisor], count);
		address %= divisor;
		divisor /= 16;
	}
}
