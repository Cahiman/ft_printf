/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:15:26 by baiannon          #+#    #+#             */
/*   Updated: 2023/12/06 16:09:12 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int ret;
	ret = write(1, &c, 1);
	return (ret);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb, int *len)
{
		if (nb == -2147483648)
			return (ft_putstr("-2147483648"));
		if (nb < 0)
		{
			nb = -nb;
			*len += ft_putchar('-');
		}
		if (nb > 9)
			ft_putnbr(nb / 10, len);
		*len +=	ft_putchar(nb % 10 + 48);
		return (*len);
}

unsigned int	ft_putnbr_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
		len += ft_putnbr_unsigned(nb / 10);
	len += ft_putchar(nb % 10 + 48);
	return (len);
}