/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkakuna <vkakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:34:34 by vkakuna           #+#    #+#             */
/*   Updated: 2021/12/23 15:59:22 by vkakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char a)
{
	write(1, &a, 1);
	return (1i );
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	define_type(char specificator, va_list ap)
{
	int	flag;

	flag = 0;
	if (specificator == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (specificator == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (specificator == 'd' || specificator == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (specificator == 'u')
		return (print_u_nb(va_arg(ap, unsigned int)));
	if (specificator == 'X' || specificator == 'x')
	{
		if (specificator == 'X')
			flag = 1;
		return (print_hex(va_arg(ap, unsigned int), flag));
	}
	if (specificator == 'p')
	{
		write(1, "0x", 2);
		return (print_ptr(va_arg(ap, unsigned long int)) + 2);
	}
	if (specificator == '%')
		ft_putchar(37);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += define_type(*(format + 1), ap);
			format++;
		}
		else
			len += ft_putchar(*(format));
		format++;
	}
	va_end(ap);
	// printf("len = %d\n", len);
	return (len);
}

// int	main(int argc, char **argv)
// {
// 	int a;
// 	a = 0;
// 	int	x;

// // // 	// int	a;
// // 	// a = 123;

// // 	// x = printf("or: %c %c %c %c\n", 'b', 'a', 'o', 'e'); //SIMILAR RESULTS
// // 	// // printf("x: %d\n", x);
// // 	// // ft_printf("my: %c %c %c %c\n", 'd', 'c', 'i', 'y');

// // 	// x = printf("or: %s\n", a); //SIMILAR RESULTS
// // 	// printf("x: %d\n", x);
// // 	// ft_printf("my: %s\n", a);

// // 	// // x = printf("or: %d\n", -2147483647);
// // 	// printf("x: %d\n", x);
// // 	// ft_printf("my: %d\n", -2147483647);

// // 	// x = printf("or: %u\n", 2147483647);
// // 	// printf("x: %d\n", x);
// // 	// ft_printf("my: %u\n", 2147483647);

// // 	// x = printf("or: %x\n", 100);
// // 	// printf("x: %d\n", x);
// // 	// ft_printf("my: %u\n", 100);	
// // 	// printf("%05i\n", a);

// // 	// x = printf("or: %X\n", 12349);
// // 	// printf("x: %d\n", x);
// // 	// ft_printf("my: %X\n", 12349);
// // 	// x = printf("or: %x\n", 12349);
// // 	// printf("x: %d\n", x);
// // // 	// ft_printf("my: %x\n", 12349);

// 	x = printf("or: %p\n", a);
// 	printf("x: %d\n", x);
// 	x = ft_printf("my: %p\n", a);
// 	return (0);
// }
