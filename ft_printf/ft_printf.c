/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:45:35 by nazouz            #+#    #+#             */
/*   Updated: 2023/11/23 19:07:07 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char format, va_list arg_ptr)
{
	int		count;

	count = 0;
	if (format == '\0')
		return (0);
	else if (format == '%')
		count = ft_putchar('%');
	else if (format == 'c')
		count = ft_putchar(va_arg(arg_ptr, int));
	else if (format == 's')
		count = ft_putstr(va_arg(arg_ptr, char *));
	else if (format == 'p')
		count = ft_print_add(va_arg(arg_ptr, void *));
	else if (format == 'd' || format == 'i')
		count = ft_putnbr(va_arg(arg_ptr, int));
	else if (format == 'u')
		count = ft_printu(va_arg(arg_ptr, unsigned int));
	else if (format == 'x')
		count = ft_printhex(va_arg(arg_ptr, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		count = ft_printhex(va_arg(arg_ptr, unsigned int), "0123456789ABCDEF");
	return (count);
}

int	ft_norminette(const char *format, va_list arg_ptr)
{
	int			count;
	int			return_value;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			return_value = ft_print_format(*(++format), arg_ptr);
			if (return_value == -1)
				return (-1);
			count += return_value;
		}
		else
		{
			return_value = ft_putchar(*format);
			if (return_value == -1)
				return (-1);
			count += return_value;
		}
		if (*format != '\0')
			format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	int			count;

	count = 0;
	va_start(arg_ptr, format);
	count = ft_norminette(format, arg_ptr);
	va_end(arg_ptr);
	return (count);
}
