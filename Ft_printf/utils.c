/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:40:23 by tomo              #+#    #+#             */
/*   Updated: 2022/06/15 04:42:42 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(STDOUT_FILENO, str, ft_strlen(str)));
}

int	ft_putptr(void *ptr)
{
	unsigned long long	num;
	int					len;

	num = (unsigned long long)ptr;
	len = 0;
	if (num >= 16)
		len += ft_putptr((void *)(num / 16));
	len += write(STDOUT_FILENO, &"0123456789abcdef"[num % 16], 1);
	return (len);
}

int	ft_putint(int num)
{
	int		len;
	char	*str_num;

	str_num = ft_itoa(num);
	len = ft_putstr(str_num);
	free(str_num);
	return (len);
}

int	ft_putuint(unsigned int num)
{
	int	len;

	len = 0;
	if (num >= 10)
		len += ft_putuint(num / 10);
	len += write(STDOUT_FILENO, &"0123456789"[num % 10], 1);
	return (len);
}

int	put_basenum(unsigned int num, char format)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += put_basenum(num / 16, format);
	if (format == 'x')
		len += write(STDOUT_FILENO, &"0123456789abcdef"[num % 16], 1);
	else if (format == 'X')
		len += write(STDOUT_FILENO, &"0123456789ABCDEF"[num % 16], 1);
	return (len);
}
