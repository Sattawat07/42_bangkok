# include <stdarg.h>
# include <unistd.h>

void	ft_putchr(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	matchf(va_list args, char specifier, int *count)
{
	if (specifier == 'c')
		ft_putchr(va_arg(args, int), count);
}

int		ft_printf(const char *f, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, f);
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			if (*f == '%')
				ft_putchr('%', &count);
			else if (*f)
				matchf(args, *f, &count);
		}
		else
			ft_putchr(*f, &count);
		if (*f)
			f++;
	}
	return (count);
}

#include <stdio.h>

int main(void)
{
	int	c;
	int c2;

	c = ft_printf("%c\n", 'h');
	c2 = printf("%c\n", 'h');
	printf("%d and %d", c, c2);
	return (0);
}