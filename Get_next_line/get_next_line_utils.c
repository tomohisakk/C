/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:40:17 by tomo              #+#    #+#             */
/*   Updated: 2022/06/29 06:42:10 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	char_c;

	i = 0;
	if (c == 0)
	{
		while (str[i] != '\0')
			i++;
		return ((char *)&str[i]);
	}
	char_c = (char)c;
	while (str[i] != '\0')
	{
		if (str[i] == char_c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

static char	*connect_array(char const *s1, char const *s2, char *ans)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ans[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ans[i] = s2[j];
		i++;
		j++;
	}
	ans[i] = '\0';
	return (ans);
}

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
	return (connect_array(s1, s2, ans));
}

char	*ft_strdup(const char *s)
{
	char	*ans;
	size_t	i;

	i = 0;
	ans = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	while (s[i] != '\0')
	{
		ans[i] = s[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
