/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoe <tomoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:36:33 by tomoe             #+#    #+#             */
/*   Updated: 2022/05/21 19:30:34 by tomoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ans;
	size_t	i;

	i = 0;
	ans = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ans)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (s[i] != '\0')
	{
		ans[i] = s[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
