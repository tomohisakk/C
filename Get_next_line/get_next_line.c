/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:07:31 by tomo              #+#    #+#             */
/*   Updated: 2022/06/16 04:43:22 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<unistd.h>



static void	restore_left_str(char **left_str)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (!*left_str[i] && *left_str[i] != '\n')
		i++;
	tmp = ft_strdup(*left_str);
	if (!tmp)
	{
		free(tmp);
		return ;
	}
	free(left_str);
	*left_str = tmp;
}

static void	compute_next_line(char **str, char *left_str)
{
	size_t	i;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return ;
	ft_strlcat(*str, left_str, i + 1);
}

static char	*strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	len_ans;

	len_ans = ft_strlen(s1) + ft_strlen(s2) + 1;
	ans = malloc(sizeof(char) * len_ans);
	if (!ans)
		return (NULL);
	ft_strlcpy(ans, s1, len_ans);
	ft_strlcat(ans, s2, len_ans);
	return (ans);
}

static char	*compute_left_str(char *left_str, int fd)
{
	char	*buffer;
	ssize_t	success_size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	success_size = 1;
	printf("okok");
	while (success_size > 0 && !ft_strchr(left_str, '\n'))
	{
		printf("okok");
		success_size = read(fd, buffer, BUFFER_SIZE);
		if (success_size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[success_size] = '\0';
		printf("okok");
		left_str = strjoin(left_str, buffer);
		printf("okok");
	}
	free(buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("okok");
	left_str = compute_left_str(left_str, fd);
	if (!left_str)
		return (NULL);
	printf("okok");
	compute_next_line(&str, left_str);
	restore_left_str(&left_str);
	return (str);
}


#include <fcntl.h>
int main(void)
{
	int		fd;

	printf("okok\n");
	fd = open("foo.txt", O_RDONLY, 0);
	printf("okok");
	printf("%s", get_next_line(fd));
	return (0);
}