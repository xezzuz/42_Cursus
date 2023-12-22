/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:15:49 by nazouz            #+#    #+#             */
/*   Updated: 2023/11/13 16:35:42 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printu(unsigned int n)
{
	int		count;
	int		return_value;

	count = 0;
	return_value = 0;
	if (n >= 10)
	{
		return_value = ft_printu(n / 10);
		if (return_value == -1)
			return (-1);
		count += return_value;
	}
	return_value = ft_putchar((n % 10) + 48);
	if (return_value == -1)
		return (-1);
	return (count + return_value);
}
