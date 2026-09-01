/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:43:48 by sboontem          #+#    #+#             */
/*   Updated: 2026/08/26 11:43:48 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	val;

	ptr = (unsigned char *)s;
	val = (unsigned char)c;
	while (n)
	{
		*ptr = val;
		ptr++;
		n--;
	}
	return (s);
}
