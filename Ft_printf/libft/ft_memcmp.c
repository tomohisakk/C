/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:32:27 by tomoe             #+#    #+#             */
/*   Updated: 2022/06/08 16:28:55 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*uchar_s1;
	const unsigned char	*uchar_s2;

	uchar_s1 = (unsigned char *)s1;
	uchar_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (uchar_s1[i] == uchar_s2[i])
	{
		if (i + 1 == n)
			return (0);
		i++;
	}
	return (uchar_s1[i] - uchar_s2[i]);
}
