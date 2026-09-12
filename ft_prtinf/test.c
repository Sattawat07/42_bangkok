#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		a;
	char	*str;
	void	*null_ptr;
	int		res1;
	int		res2;

	a = 42;
	str = "Hello 42";
	null_ptr = NULL;

	printf("[ Test 1: Stack Memory Address ]\n");
	res1 = printf("   printf: [%p]\n", (void *)&a);
	res2 = ft_printf("ft_printf: [%p]\n", (void *)&a);
	printf("Count -> printf: %d | ft_printf: %d\n\n", res1, res2);

	printf("[ Test 2: String Literal Address ]\n");
	res1 = printf("   printf: [%p]\n", (void *)str);
	res2 = ft_printf("ft_printf: [%p]\n", (void *)str);
	printf("Count -> printf: %d | ft_printf: %d\n\n", res1, res2);

	printf("[ Test 3: NULL Pointer ]\n");
	res1 = printf("   printf: [%p]\n", null_ptr);
	res2 = ft_printf("ft_printf: [%p]\n", null_ptr);
	printf("Count -> printf: %d | ft_printf: %d\n\n", res1, res2);

	printf("[ Test 4: Multiple Pointers ]\n");
	res1 = printf("   printf: [%p] | [%p]\n", (void *)&a, null_ptr);
	res2 = ft_printf("ft_printf: [%p] | [%p]\n", (void *)&a, null_ptr);
	printf("Count -> printf: %d | ft_printf: %d\n\n", res1, res2);

	return (0);
}