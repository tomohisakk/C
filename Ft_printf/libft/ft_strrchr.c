/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:35:36 by tomoe             #+#    #+#             */
/*   Updated: 2022/06/09 18:27:43 by tkawakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	char_c;
	size_t	len_str;

	len_str = ft_strlen(str);
	char_c = (char)c;
	if (char_c == '\0')
	{
		while (*str != '\0')
			str++;
		return ((char *)str);
	}
	while (len_str >= 1)
	{
		len_str--;
		if (str[len_str] == char_c)
			return ((char *)&str[len_str]);
	}
	return (NULL);
}
