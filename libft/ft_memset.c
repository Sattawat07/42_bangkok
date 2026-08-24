#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	val;

	ptr = (unsigned char *)b;
	val = (unsigned char)c;
	while (len)
	{
		*ptr = val;
		ptr++;
		len--;
	}
	return (b);
}
