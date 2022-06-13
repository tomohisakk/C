/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoe <tomoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:36:11 by tomoe             #+#    #+#             */
/*   Updated: 2022/05/25 20:29:58 by tkawakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	snum(char const *s1, char const *set)
{
	size_t	ans;

	ans = 0;
	while (s1[ans] != '\0' && ft_strchr(set, s1[ans]) != 0)
		ans++;
	if (s1[ans] == '\0')
		return (0);
	return (ans);
}

size_t	fnum(char const *s1, char const *set)
{
	size_t	ans;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	ans = 0;
	while (ft_strchr(set, s1[len_s1 - 1 - ans]) != 0)
	{
		if (len_s1 - 1 - ans == 0)
			return (0);
		ans++;
	}
	return (len_s1 - ans);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_snum;
	size_t	len_fnum;
	char	*ans;

	if (!s1)
		return (NULL);
	len_snum = snum(s1, set);
	len_fnum = fnum(s1, set);
	ans = ft_substr(s1, len_snum, len_fnum - len_snum);
	return (ans);
}
