/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoe <tomoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:33:46 by tomoe             #+#    #+#             */
/*   Updated: 2022/05/24 08:30:06 by tomoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	char	min;
	int		i;
	long	num;

	min = '-';
	num = n;
	i = 1;
	if (n < 0)
	{
		num *= -1;
		write(fd, &min, 1);
	}
	while (n / 10 != 0)
	{
		n /= 10;
		i *= 10;
	}
	while (i > 0)
	{
		c = '0' + (num / i);
		write(fd, &c, 1);
		num -= (num / i) * i;
		i /= 10;
	}
}
