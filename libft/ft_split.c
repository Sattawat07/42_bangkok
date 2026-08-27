/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:44:05 by sboontem          #+#    #+#             */
/*   Updated: 2026/08/27 22:14:11 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (!is_sep(s[i], c) && (i == 0 || is_sep(s[i - 1], c)))
			count++;
		i++;
	}
	return (count);
}

static char	*split_word(char const *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && !is_sep(s[len], c))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

static void	free_all(char **ret, int i)
{
	while (i > 0)
	{
		i--;
		free(ret[i]);
	}
	free(ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s && ++i)
		{
			ret[i - 1] = split_word(s, c);
			if (!ret[i - 1])
				return (free_all(ret, i - 1), NULL);
			while (*s && !is_sep(*s, c))
				s++;
		}
	}
	return (ret[i] = NULL, ret);
}
