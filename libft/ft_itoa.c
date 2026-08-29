/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:42:57 by sboontem          #+#    #+#             */
/*   Updated: 2026/08/29 09:54:19 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long n)
{
	int	count;

	if (n <= 0)
		count = 1;
	else
		count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	convert_to_char(char *str, long n, int len)
{
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	number;
	char	*str;
	int		len;

	number = n;
	len = count_digit(number);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	convert_to_char(str, number, len);
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *str = ft_itoa(-4224);
// 	if (str)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 	}
// 	return (0);
// }
