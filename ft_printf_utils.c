/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkakuna <vkakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:56:50 by vkakuna           #+#    #+#             */
/*   Updated: 2021/12/23 16:00:23 by vkakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_len(int n)
{
	int	nb_len;

	nb_len = 0;
	while (n != 0)
	{
		n = n / 10;
		nb_len++;
	}
	return (nb_len);
}

int	print_ptr(unsigned long int nb)
{
	int	i;

	// i = ft_len(nb);
	if (nb >= 16)
	{
		print_ptr(nb / 16);
		print_ptr(nb % 16);
	}
	else if (nb <= 9)
		ft_putchar(nb + '0');
	else if (nb > 9)
		ft_putchar(nb + 87);
	return (i);
}

int	print_hex(unsigned long long int nb, int flag)
{
	int	i;

	// i = ft_len(nb);
	if (nb >= 16)
	{
		print_hex(nb / 16, flag);
		print_hex(nb % 16, flag);
	}
	else if (nb <= 9)
		ft_putchar(nb + '0');
	else if (nb > 9 && flag == 1)
		i += ft_putchar(nb + 55);
	else if (nb > 9 && flag == 0)
		i += ft_putchar(nb + 87);
	return (i);
}

int	print_u_nb(unsigned int nb)
{
	int	i;

	i = ft_len(nb);
	if (nb >= 10)
	{
		print_u_nb(nb / 10);
		print_u_nb (nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = ft_len(nb);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = (unsigned int)nb * -1;
		i++;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}	
	else
	{
		ft_putchar (nb + '0');
	}
	return (i);
}
