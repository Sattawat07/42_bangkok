/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 21:37:50 by sboontem          #+#    #+#             */
/*   Updated: 2026/09/09 21:37:50 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *f, ...);
void	matchf(va_list args, char specifier, int *count);
int		ft_strlen(char *s)
void	ft_putchr(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbr_unsigned(unsigned int n, int *count);
void	ft_puthex(unsigned int num, char specifier, int *count);
void	ft_putptr(void *ptr, int *count);

#endif
