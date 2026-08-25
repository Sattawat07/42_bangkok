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
