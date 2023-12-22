/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:32:48 by nazouz            #+#    #+#             */
/*   Updated: 2023/11/18 11:55:56 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ulong_hex(unsigned long n)
{
	int			count;
	char		*hex;
	int			return_value;

	count = 0;
	return_value = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_print_ulong_hex((n / 16));
	return_value = ft_putchar(hex[n % 16]);
	if (return_value == -1)
		return (-1);
	return (count + return_value);
}

int	ft_print_add(void *ptr)
{
	int			count;
	int			return_value;

	count = 0;
	return_value = 0;
	if (!ptr)
		return (ft_putstr("0x0"));
	return_value = ft_putstr("0x");
	if (return_value == -1)
		return (-1);
	return (count + return_value + ft_print_ulong_hex((unsigned long)ptr));
}
