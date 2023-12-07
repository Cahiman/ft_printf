/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:39:45 by baiannon          #+#    #+#             */
/*   Updated: 2023/12/06 16:07:24 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char check_char(char c, va_list args)
{
	int	len;
	
	len = 0;
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'i' || c == 'd')
		return ft_putnbr(va_arg(args, int), &len);
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'x' || c == 'X')
		return (ft_hexa_base(va_arg(args, unsigned int), c));
	if (c == 'p')
		return (ft_hexa_p(va_arg(args, void *)));
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		len;
	
	va_start (args, str);
	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
			len += check_char(str[++i], args);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (len);
}