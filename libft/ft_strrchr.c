/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:44:32 by sboontem          #+#    #+#             */
/*   Updated: 2026/08/26 11:44:32 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ret;

	ptr = (char *)s;
	ret = NULL;
	while (1)
	{
		if (*ptr == (char)c)
			ret = ptr;
		if (*ptr == '\0')
			break ;
		ptr++;
	}
	return (ret);
}
