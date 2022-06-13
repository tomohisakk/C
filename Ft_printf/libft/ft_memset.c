/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:40:02 by tomo              #+#    #+#             */
/*   Updated: 2022/05/28 22:40:03 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_temp;
	unsigned char	uchar_c;

	s_temp = (unsigned char *)s;
	uchar_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		s_temp[i] = uchar_c;
		i++;
	}
	return (s);
}
