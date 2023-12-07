/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:17 by baiannon          #+#    #+#             */
/*   Updated: 2023/12/06 16:04:45 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb, int *len);
int		ft_printf(const char *str, ...);
int		ft_hexa_base(unsigned int n, char c);
int		ft_hexa(unsigned long int n);
int		ft_hexa_p(void *ptr);
char	check_char(char c, va_list args);
unsigned int	ft_putnbr_unsigned(unsigned int nb);

#endif