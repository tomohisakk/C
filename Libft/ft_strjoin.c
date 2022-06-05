/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoe <tomoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:15:27 by tomoe             #+#    #+#             */
/*   Updated: 2022/05/11 10:16:23 by tomoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	len_ans;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len_ans = ft_strlen(s1) + ft_strlen(s2) + 1;
	ans = malloc(sizeof(char) * len_ans);
	if (!ans)
		return (NULL);
	ft_strlcpy(ans, s1, len_ans);
	ft_strlcat(ans, s2, len_ans);
	return (ans);
}
