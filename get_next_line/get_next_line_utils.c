/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 21:52:45 by sboontem          #+#    #+#             */
/*   Updated: 2026/09/24 21:52:45 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (1)
	{
		if (*ptr == (char)c)
			return (ptr);
		if (*ptr == '\0')
			break ;
		ptr++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

static char	*ft_grow(char *line, size_t len, size_t *capacity, size_t needed)
{
	size_t	new_capacity;
	char	*new_line;

	new_capacity = *capacity;
	while (new_capacity < needed)
	{
		if (new_capacity > (size_t)-1 / 2)
			new_capacity = needed;
		else
			new_capacity *= 2;
	}
	new_line = malloc(new_capacity);
	if (!new_line)
		return (NULL);
	if (line)
		ft_memcpy(new_line, line, len);
	free(line);
	*capacity = new_capacity;
	return (new_line);
}

char	*ft_strjoin(char *line, const char *buffer, size_t *len,
		size_t *capacity)
{
	size_t	add;
	char	*new_line;

	add = ft_strlen(buffer);
	if (add > (size_t)-1 - *len - 1)
		return (free(line), NULL);
	if (*capacity < *len + add + 1)
	{
		new_line = ft_grow(line, *len, capacity, *len + add + 1);
		if (!new_line)
			return (free(line), NULL);
		line = new_line;
	}
	ft_memcpy(line + *len, buffer, add);
	*len += add;
	line[*len] = '\0';
	return (line);
}
