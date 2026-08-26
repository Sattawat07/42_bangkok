/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:44:24 by sboontem          #+#    #+#             */
/*   Updated: 2026/08/27 01:33:05 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
