/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:20:51 by tomoe             #+#    #+#             */
/*   Updated: 2022/06/08 16:50:14 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uchar_s1;
	unsigned char	*uchar_s2;

	uchar_s1 = (unsigned char *)s1;
	uchar_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (uchar_s1[i] == uchar_s2[i])
	{
		if (uchar_s1[i] == '\0' || i + 1 == n)
			return (0);
		i++;
	}
	return (uchar_s1[i] - uchar_s2[i]);
}
