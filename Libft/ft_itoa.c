/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoe <tomoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:07:13 by tomoe             #+#    #+#             */
/*   Updated: 2022/05/25 20:27:35 by tkawakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	dnum(long i)
{
	size_t	ans;

	ans = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		ans++;
	}
	while (i > 0)
	{
		i /= 10;
		ans++;
	}
	return (ans);
}

char	*ft_itoa(int n)
{
	char		*ans;
	size_t		len_digit;
	long		long_n;

	long_n = (long)n;
	len_digit = dnum(long_n);
	ans = malloc((len_digit + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	ans[len_digit] = '\0';
	if (n == 0)
		ans[0] = '0';
	if (n < 0)
	{
		ans[0] = '-';
		long_n *= -1;
	}
	while (long_n > 0)
	{
		ans[len_digit - 1] = long_n % 10 + '0';
		long_n /= 10;
		len_digit--;
	}
	return (ans);
}
