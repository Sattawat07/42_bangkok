/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboontem <sboontem@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 11:55:10 by sboontem          #+#    #+#             */
/*   Updated: 2026/09/13 11:55:10 by sboontem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	matchf(va_list args, char specifier, int *count)
{
	if (specifier == 'c')
		ft_putchr(va_arg(args, int), count);
	else if (specifier == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (specifier == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (specifier == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), count);
	else if (specifier == 'x' || specifier == 'X')
		ft_puthex(va_arg(args, unsigned int), specifier, count);
}

int	ft_printf(const char *f, ...)
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
	va_end(args);
	return (count);
}

// // command
// // 1. make && make clean
// // 2. cc ft_printf.c libftprintf.a -I. && ./a.out
// #include <stdio.h>
// #include <limits.h>

// void	print_header(char *title)
// {
// 	printf("\n==================================================\n");
// 	printf("  %s\n", title);
// 	printf("==================================================\n");
// }

// void	test_check(char *test_name, int r1, int r2)
// {
// 	printf("   --> Result (%s) : printf = %-3d | ft_printf = %-3d ",
// 				test_name, r1, r2);
// 	if (r1 == r2)
// 		printf("[OK]\n\n");
// 	else
// 		printf("[KO] <-- BUG!\n\n");
// }

// int	main(void)
// {
// 	int		r1;
// 	int		r2;
// 	char	*nil_str;
// 	void	*nil_ptr;

// 	nil_str = NULL;
// 	nil_ptr = NULL;

// 	/* ---------------------------------------------------------------------- */
// 	/* 1. CHAR (%c)                                                           */
// 	/* ---------------------------------------------------------------------- */
// 	print_header("1. CHAR (%c)");

// 	printf("[ Test 1.1: ASCII Char ]\n");
// 	r1 = printf("     printf: [%c]\n", 'a');
// 	r2 = ft_printf("  ft_printf: [%c]\n", 'a');
// 	test_check("Test 1.1", r1, r2);

// 	printf("[ Test 1.2: Null Char '\\0' ]\n");
// 	r1 = printf("     printf: [%c]\n", '\0');
// 	r2 = ft_printf("  ft_printf: [%c]\n", '\0');
// 	test_check("Test 1.2", r1, r2);

// 	printf("[ Test 1.3: Multiple Chars ]\n");
// 	r1 = printf("     printf: [%c][%c][%c]\n", '4', '2', '!');
// 	r2 = ft_printf("  ft_printf: [%c][%c][%c]\n", '4', '2', '!');
// 	test_check("Test 1.3", r1, r2);

// 	/* ---------------------------------------------------------------------- */
// 	/* 2. STRING (%s)                                                         */
// 	/* ---------------------------------------------------------------------- */
// 	print_header("2. STRING (%s)");

// 	printf("[ Test 2.1: Standard String ]\n");
// 	r1 = printf("     printf: [%s]\n", "Hello 42 Bangkok!");
// 	r2 = ft_printf("  ft_printf: [%s]\n", "Hello 42 Bangkok!");
// 	test_check("Test 2.1", r1, r2);

// 	printf("[ Test 2.2: Empty String ]\n");
// 	r1 = printf("     printf: [%s]\n", "");
// 	r2 = ft_printf("  ft_printf: [%s]\n", "");
// 	test_check("Test 2.2", r1, r2);

// 	printf("[ Test 2.3: NULL String Pointer ]\n");
// 	r1 = printf("     printf: [%s]\n", nil_str);
// 	r2 = ft_printf("  ft_printf: [%s]\n", nil_str);
// 	test_check("Test 2.3", r1, r2);

// 	/* ---------------------------------------------------------------------- */
// 	/* 3. POINTER (%p)                                                        */
// 	/* ---------------------------------------------------------------------- */
// 	print_header("3. POINTER (%p)");

// 	printf("[ Test 3.1: Stack Memory Pointer ]\n");
// 	r1 = printf("     printf: [%p]\n", (void *)&r1);
// 	r2 = ft_printf("  ft_printf: [%p]\n", (void *)&r1);
// 	test_check("Test 3.1", r1, r2);

// 	printf("[ Test 3.2: NULL Pointer / (void *)0 ]\n");
// 	r1 = printf("     printf: [%p]\n", nil_ptr);
// 	r2 = ft_printf("  ft_printf: [%p]\n", nil_ptr);
// 	test_check("Test 3.2", r1, r2);

// 	printf("[ Test 3.3: ULONG_MAX Pointer ]\n");
// 	r1 = printf("     printf: [%p]\n", (void *)(unsigned long)-1);
// 	r2 = ft_printf("  ft_printf: [%p]\n", (void *)(unsigned long)-1);
// 	test_check("Test 3.3", r1, r2);

// 	/* ---------------------------------------------------------------------- */
// 	/* 4. SIGNED INT (%d / %i)                                                */
// 	/* ---------------------------------------------------------------------- */
// 	print_header("4. SIGNED INT (%d / %i)");

// 	printf("[ Test 4.1: Zero ]\n");
// 	r1 = printf("     printf: [%d] [%i]\n", 0, 0);
// 	r2 = ft_printf("  ft_printf: [%d] [%i]\n", 0, 0);
// 	test_check("Test 4.1", r1, r2);

// 	printf("[ Test 4.2: Small Positive & Negative ]\n");
// 	r1 = printf("     printf: [%d] [%i]\n", 42, -42);
// 	r2 = ft_printf("  ft_printf: [%d] [%i]\n", 42, -42);
// 	test_check("Test 4.2", r1, r2);

// 	printf("[ Test 4.3: INT_MAX & INT_MIN ]\n");
// 	r1 = printf("     printf: [%d] [%i]\n", INT_MAX, INT_MIN);
// 	r2 = ft_printf("  ft_printf: [%d] [%i]\n", INT_MAX, INT_MIN);
// 	test_check("Test 4.3", r1, r2);

// 	/* ---------------------------------------------------------------------- */
// 	/* 5. UNSIGNED INT (%u)                                                   */
// 	/* ---------------------------------------------------------------------- */
// 	print_header("5. UNSIGNED INT (%u)");

// 	printf("[ Test 5.1: Zero & UINT_MAX ]\n");
// 	r1 = printf("     printf: [%u] [%u]\n", 0, UINT_MAX);
// 	r2 = ft_printf("  ft_printf: [%u] [%u]\n", 0, UINT_MAX);
// 	test_check("Test 5.1", r1, r2);

// 	/* ---------------------------------------------------------------------- */
// 	/* 6. HEXADECIMAL (%x / %X)                                               */
// 	/* ---------------------------------------------------------------------- */
// 	print_header("6. HEXADECIMAL (%x / %X)");

// 	printf("[ Test 6.1: Zero & UINT_MAX Hex ]\n");
// 	r1 = printf("     printf: [%x] [%X]\n", 0, UINT_MAX);
// 	r2 = ft_printf("  ft_printf: [%x] [%X]\n", 0, UINT_MAX);
// 	test_check("Test 6.1", r1, r2);

// 	printf("[ Test 6.2: Single Hex Boundaries (10 & 15) ]\n");
// 	r1 = printf("     printf: [%x] [%X]\n", 10, 15);
// 	r2 = ft_printf("  ft_printf: [%x] [%X]\n", 10, 15);
// 	test_check("Test 6.2", r1, r2);

// 	/* ---------------------------------------------------------------------- */
// 	/* 7. PERCENT SIGN (%%)                                                   */
// 	/* ---------------------------------------------------------------------- */
// 	print_header("7. PERCENT SIGN (%%)");

// 	printf("[ Test 7.1: Escaped Percents ]\n");
// 	r1 = printf("     printf: [%%] [%%%%] [%%d]\n");
// 	r2 = ft_printf("  ft_printf: [%%] [%%%%] [%%d]\n");
// 	test_check("Test 7.1", r1, r2);

// 	/* ---------------------------------------------------------------------- */
// 	/* 8. MIXED CASES                                                         */
// 	/* ---------------------------------------------------------------------- */
// 	print_header("8. MIXED CASES");

// 	printf("[ Test 8.1: All Specifiers Combined ]\n");
// 	r1 = printf("     printf: %c %s %p %d %u %x %%\n",
// 					'A', "42", nil_ptr, INT_MIN, UINT_MAX, 255);
// 	r2 = ft_printf("  ft_printf: %c %s %p %d %u %x %%\n",
// 					'A', "42", nil_ptr, INT_MIN, UINT_MAX, 255);
// 	test_check("Test 8.1", r1, r2);

// 	return (0);
// }