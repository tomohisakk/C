/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:07:31 by tomo              #+#    #+#             */
/*   Updated: 2022/06/16 04:12:35 by tomo             ###   ########.fr       */
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

static char	*compute_left_str(char *left_str, int fd)
{
	char	*buffer;
	ssize_t	success_size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	success_size = 1;
	while (success_size > 0 && !ft_strchr(left_str, '\n'))
	{
		success_size = read(fd, buffer, BUFFER_SIZE);
		if (success_size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[success_size] = '\0';
		left_str = ft_strjoin(left_str, buffer);
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
	compute_next_line(&str, left_str);
	restore_left_str(&left_str);
	return (str);
}


#include <fcntl.h>
int main(void)
{
	int		fd;

	//printf("okok\n");
	fd = open("foo.txt", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	return (0);
}