/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:47:59 by tomo              #+#    #+#             */
/*   Updated: 2022/06/13 19:53:48 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	size_t	i;
	va_list	args;	

	len = 0;
	i = 0;
	errno = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			compute_format(format[i + 1], args, len, i);
		else
			len += write(STDOUT_FILENO, &format[i++], 1);
		if (!errno || len < 0)
			break ;
	}
	va_end(args);
	if (!errno || len < 0)
		return (-1);
	return (len);
}

static int	compute_format(char format, va_list args, int len, size_t i)
{
	unsigned char	u_char;

	if (*format == 'c')
	{
		u_char = (unsigned char)va_arg(*format, int);
		len += write(STDOUT_FILENO, &u_char, 1);
	}
	else if (c == 's')
		putchar(format, len);
	else if (c == 'd' || c == 'i')
		len += putnb(va_arg(format, int));
	else if (c == 'p')
		len += put_basenum((size_t)va_arg(*format, void *), "0123456789abcdef", c);
	else if (c == 'u')
		len += put_basenum(va_arg(*format, unsigned int), "0123456789", c);
	else if (c == 'x')
		len += put_basenum(va_arg(*format, unsigned int), "0123456789abcdef", c);
	else if (c == 'X')
		len += put_basenum(va_arg(*format, unsigned int), "0123456789ABCDEF", c);
	else if (c == '%')
		len += write(STDOUT_FILENO, '%', 1);
	if (c == '\0')
		i++;
	else
		i += 2;
}	
	
static int	put_basenum(size_t nb, char base, char c)
{
	size_t	len_base;
	size_t	i;
	char	char_num[18];

	len_base = ft_strlen(base);
	if (!nb)
	{
		if (c == 'p')
			return (write(STDOUT_FILENO, "0x0", 3));
		return (write(STDOUT_FILENO, '0', 1));
	}
	i = 0;
	while (nb)
	{
		char_num[17 - i++] = base[nb % len_base];
		nb /= len_base;
	}
	if (c == 'p')
	{
		char_num[17 - i - 1] = '0';
		char_num[17 - i] = 'x';
		i += 2;
	}
	return (write(STDOUT_FILENO, &char_num[17 - i - 1], i));
}

