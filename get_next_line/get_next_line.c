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
	int		rsize;
	size_t	len;
	size_t	capacity;

	len = ft_strlen(line);
	capacity = len + 1;
	rsize = 1;
	while (rsize > 0)
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

	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_read_line(fd, line, buffer);
	free(buffer);
	return (line);
}

char	*ft_extract_line(char *line)
{
	int		len;
	int		i;
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

char	*ft_remain_buff(char *line)
{
	int		len;
	int		i;
	char	*buffer;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (!line[len] || !line[++len])
		return (free(line), NULL);
	buffer = malloc(sizeof(char) * (ft_strlen(line) - len + 1));
	if (!buffer)
		return (free(line), NULL);
	i = 0;
	while (line[len + i])
	{
		buffer[i] = line[len + i];
		i++;
	}
	buffer[i] = '\0';
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*r_buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r_buffer = ft_get_line(fd, r_buffer);
	if (!r_buffer)
		return (NULL);
	next_line = ft_extract_line(r_buffer);
	r_buffer = ft_remain_buff(r_buffer);
	return (next_line);
}
