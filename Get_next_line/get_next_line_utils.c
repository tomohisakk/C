/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:40:17 by tomo              #+#    #+#             */
/*   Updated: 2022/06/20 15:51:34 by tomo             ###   ########.fr       */
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

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len_src;

	if (!src)
	{
		dest[0] = '\0';
		return (0);
	}
	len_src = ft_strlen(src);
	if (n == 0)
		return (len_src);
	if ((len_src + 1) < n)
		ft_memcpy(dest, src, len_src + 1);
	else if (n != 0)
	{
		ft_memcpy(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (len_src);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	char_c;

	i = 0;
	if (!str)
		return (NULL);
	if (c == 0)
		return ((char *)&str[ft_strlen(str)]);
	char_c = (char)c;
	while (str[i] != '\0' && str[i] != char_c)
		i++;
	if (str[i] == char_c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	len_ans;

	len_ans = ft_strlen(s1) + ft_strlen(s2) + 1;
	ans = malloc(sizeof(char) * len_ans);
	if (!ans)
		return (NULL);
	ft_strlcpy(ans, s1, len_ans);
	ft_strlcpy(ans, s1, len_ans);
	return (ans);
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