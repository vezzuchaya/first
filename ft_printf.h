/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkakuna <vkakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:08:33 by vkakuna           #+#    #+#             */
/*   Updated: 2021/12/23 14:53:29 by vkakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	define_type(char specificator, va_list ap);
int	ft_putstr(char *str);
int	ft_putchar(char a);
int	print_ptr(unsigned long int nb);
int	print_hex(unsigned long long int nb, int flag);
int	print_u_nb(unsigned int nb);
int	ft_putnbr(int nb);

#endif