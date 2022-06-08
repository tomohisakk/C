/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:07:50 by tomoe             #+#    #+#             */
/*   Updated: 2022/06/08 16:27:47 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str_temp;
	unsigned char		cast_c;

	str_temp = (unsigned char *)s;
	cast_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str_temp[i] == cast_c)
			return ((void *)&str_temp[i]);
		i++;
	}
	return (NULL);
}
