/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 21:42:45 by sboontem          #+#    #+#             */
/*   Updated: 2026/09/09 21:42:45 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	matchf(va_list args, char specifier, int *count)
{
	if (specifier == 'c')
		ft_putchr(va_arg(args, int), count);
	else if (specifier == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (specifier == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (specifier == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), count);
	else if (specifier == 'x' || specifier == 'X')
		ft_puthex(va_arg(args, unsigned int), specifier, count);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, f);
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			if (*f == '%')
				ft_putchr('%', &count);
			else if (*f)
				matchf(args, *f, &count);
		}
		else
			ft_putchr(*f, &count);
		if (*f)
			f++;
	}
	return (count);
}

// #include <stdio.h>

// int main(void)
// {
// 	int	c;
// 	c = ft_printf("%c", 'h');
// 	printf("%d", c);
// 	return (0);
// }