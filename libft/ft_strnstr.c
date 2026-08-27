/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:44:28 by sboontem          #+#    #+#             */
/*   Updated: 2026/08/26 11:44:28 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *subs, size_t len)
{
	size_t	i;
	size_t	j;

	if (*subs == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (subs[j] != '\0' && (i + j) < len
			&& str[i + j] == subs[j])
			j++;
		if (subs[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
