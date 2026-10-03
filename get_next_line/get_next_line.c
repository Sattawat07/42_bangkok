/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 21:57:33 by sboontem          #+#    #+#             */
/*   Updated: 2026/09/24 21:57:33 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *line, char *buffer)
{
	ssize_t	rsize;
	size_t	len;
	size_t	capacity;

	len = ft_strlen(line);
	capacity = len + 1;
	rsize = 1;
	while (rsize > 0 && !ft_strchr(line, '\n'))
	{
		rsize = read(fd, buffer, BUFFER_SIZE);
		if (rsize == -1)
			return (free(line), NULL);
		if (rsize == 0)
			break ;
		buffer[rsize] = '\0';
		line = ft_strjoin(line, buffer, &len, &capacity);
		if (!line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

char	*ft_get_line(int fd, char *line)
{
	char	*buffer;

	if (ft_strchr(line, '\n'))
		return (line);
	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free(line), NULL);
	line = ft_read_line(fd, line, buffer);
	free(buffer);
	return (line);
}

char	*ft_extract_line(char *line)
{
	size_t	len;
	size_t	i;
	char	*buffer;

	if (!line || !line[0])
		return (NULL);
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len] == '\n')
		len++;
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buffer[i] = line[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_remain_buff(char *line, int *error)
{
	size_t	len;
	char	*buffer;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (!line[len] || !line[++len])
		return (free(line), NULL);
	buffer = malloc(sizeof(char) * (ft_strlen(line) - len + 1));
	if (!buffer)
	{
		*error = 1;
		return (free(line), NULL);
	}
	ft_memcpy(buffer, line + len, ft_strlen(line + len) + 1);
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*r_buffer;
	char		*next_line;
	int			error;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
		return (free(r_buffer), r_buffer = NULL, NULL);
	r_buffer = ft_get_line(fd, r_buffer);
	if (!r_buffer)
		return (NULL);
	next_line = ft_extract_line(r_buffer);
	if (!next_line)
		return (free(r_buffer), r_buffer = NULL, NULL);
	error = 0;
	r_buffer = ft_remain_buff(r_buffer, &error);
	if (error)
		return (free(next_line), NULL);
	return (next_line);
}
