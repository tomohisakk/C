/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:47:59 by tomo              #+#    #+#             */
/*   Updated: 2022/06/16 03:39:07 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	compute_format(char format, va_list args)
{
	unsigned char	uchar;

	if (format == 'c')
	{
		uchar = (unsigned char)va_arg(args, int);
		return (write(STDOUT_FILENO, &uchar, 1));
	}
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putint(va_arg(args, int)));
	else if (format == 'p')
	{
		ft_putstr("0x");
		return (ft_putptr(va_arg(args, void *)) + 2);
	}
	else if (format == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (put_basenum(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (write(STDOUT_FILENO, '%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			len += compute_format(format[++i], args);
		else
			len += write(STDOUT_FILENO, &format[i], 1);
		if (format[i])
			i++;
	}
	va_end(args);
	return (len);
}
