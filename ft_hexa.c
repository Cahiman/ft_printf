/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:48:16 by baiannon          #+#    #+#             */
/*   Updated: 2023/12/06 16:07:49 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_base(unsigned int n, char c)
{
	char	*hexa;
	int		len;

	len = 0;
	if (c >= 'a' && c <= 'z')
		hexa = "0123456789abcdef";
	else if (c >= 'A' && c <= 'Z')
		hexa = "0123456789ABCDEF";
	else
		return (0);
	if (n > 15)
		len += ft_hexa_base(n / 16, c);
	len += ft_putchar(hexa[n % 16]);
	return (len);
}

int	ft_hexa(unsigned long int n)
{
	char	*hexa;
	int		len;

	len = 0;
	hexa = "0123456789abcdef";
	if (n > 15)
		len += ft_hexa(n / 16);
	len += ft_putchar(hexa[n % 16]);
	return (len);
}

int ft_hexa_p(void *ptr)
{
	int	len;
	
	if (!ptr)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x") + ft_hexa((unsigned long int)ptr);
	return (len);
}