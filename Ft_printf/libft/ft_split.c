/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoe <tomoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:35:12 by tomoe             #+#    #+#             */
/*   Updated: 2022/05/24 21:13:04 by tomoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	len_str(char const *s, char c)
{
	size_t	i;
	size_t	ans;

	i = 0;
	ans = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			ans++;
		i++;
	}
	return (ans);
}

size_t	range_array(char const *s, char c)
{
	size_t	i;
	size_t	ans;

	i = 0;
	ans = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ans++;
			if (s[i + 1] == c || s[i + 1] == '\0')
				return (ans);
		}
		i++;
	}
	return (ans);
}

char	**free_array(char **ans, size_t x)
{
	while (x > 0)
	{
		x--;
		free(ans[x]);
	}
	free(ans);
	return (NULL);
}

char	**cpy_array(char const *s, char **ans, char c)
{
	size_t	x;

	x = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			ans[x] = ft_substr(s, 0, range_array(s, c));
			if (ans[x] == NULL)
				return (free_array(ans, x));
			x++;
		}
		s += range_array(s, c);
	}
	ans[x] = NULL;
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;

	if (!s)
		return (NULL);
	ans = malloc(sizeof(char *) * (len_str(s, c) + 1));
	if (!ans)
		return (NULL);
	return (cpy_array(s, ans, c));
}
