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
	char	*base;
	char	buffer[10];
	int		i;

	i = 0;
	if (num == 0)
	{
		ft_putchr('0', count);
		return ;
	}
	if (specifier == 'x')
		base = "0123456789abcdef";
	else if (specifier == 'X')
		base = "0123456789ABCDEF";
	while (num > 0)
	{
		buffer[i++] = base[num % 16];
		num /= 16;
	}
	while (i > 0)
		ft_putchr(buffer[--i], count);
}

void	ft_putptr(void *ptr, int *count)
{
	char			*base;
	char			buffer[16];
	int				i;
	unsigned long	address;

	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	base = "0123456789abcdef";
	address = (unsigned long)ptr;
	i = 0;
	while (address > 0)
	{
		buffer[i++] = base[address % 16];
		address /= 16;
	}
	while (i > 0)
		ft_putchr(buffer[--i], count);
}
