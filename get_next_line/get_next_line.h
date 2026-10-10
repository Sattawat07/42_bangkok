/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sattawat <sboontem@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 07:37:31 by sattawat          #+#    #+#             */
/*   Updated: 2026/10/10 07:39:21 by sattawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_get_line(int fd, char *line);
char	*ft_extract_line(char *line);
char	*ft_remain_buff(char *line, int *error);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *line, const char *buffer, size_t *len,
			size_t *capacity);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
