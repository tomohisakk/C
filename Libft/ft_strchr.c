/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:36:15 by tomoe             #+#    #+#             */
/*   Updated: 2022/06/08 16:47:02 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	char_c;

	i = 0;
	char_c = (char)c;
	while (str[i] != '\0' && str[i] != char_c)
		i++;
	if (str[i] == char_c)
		return ((char *)&str[i]);
	return (NULL);
}
