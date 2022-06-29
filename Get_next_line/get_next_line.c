/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:07:31 by tomo              #+#    #+#             */
/*   Updated: 2022/06/29 19:13:15 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

static char	*restore_left_str(char *left_str)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (left_str[i] != '\0' && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	i++;
	tmp = ft_strdup(&left_str[i]);
	free(left_str);
	if (!tmp)
		return (NULL);
	left_str = tmp;
	return (left_str);
}

static char	*compute_next_line(char *left_str)
{
	size_t	i;
	char	*str;

	i = 0;
	while (left_str[i] != '\0' && left_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i])
	{
		str[i] = left_str[i];
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*all_free(char *free1, char *free2)
{
	free(free1);
	free(free2);
	return (NULL);
}

static char	*compute_left_str(char *left_str, int fd)
{
	char	*buffer;
	ssize_t	success_size;
	char	*tmp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	success_size = 1;
	while (!ft_strchr(left_str, '\n') && success_size != 0)
	{
		success_size = read(fd, buffer, BUFFER_SIZE);
		if (success_size == -1 || (success_size == 0 && left_str[0] == '\0'))
			return (all_free(buffer, left_str));
		buffer[success_size] = '\0';
		tmp = ft_strjoin(left_str, buffer);
		if (!tmp)
			return (all_free(buffer, left_str));
		free(left_str);
		left_str = tmp;
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
	if (!left_str)
	{
		left_str = ft_strdup("");
		if (!left_str)
			return (NULL);
	}
	left_str = compute_left_str(left_str, fd);
	if (!left_str)
		return (NULL);
	str = compute_next_line(left_str);
	if (!str)
	{
		free(left_str);
		return (NULL);
	}
	left_str = restore_left_str(left_str);
	return (str);
}

/*
int main(void)
{
	int		fd;
	//printf("okok\n");
	fd = open("foo", O_RDONLY, 0);
	//printf("fd: %d\n", fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
*/