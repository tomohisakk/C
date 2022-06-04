/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:36:15 by tomoe             #+#    #+#             */
/*   Updated: 2022/05/30 09:39:18 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	char_c;

	i = 0;
	char_c = (char)c;
	if (char_c == 0)
	{
		while (str[i] != '\0')
			str++;
		return ((char *)str);
	}
	while (str[i] != '\0')
	{
		if (str[i] == char_c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
