/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:32:15 by tomoe             #+#    #+#             */
/*   Updated: 2022/05/30 09:39:45 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t s)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	if (s == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i < s)
	{
		j = 0;
		while (s1[i] == s2[j] && i < s)
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i - j]);
			i++;
			j++;
		}
		i++;
	}
	return (NULL);
}
