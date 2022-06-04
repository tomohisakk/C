/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:03:38 by tomoe             #+#    #+#             */
/*   Updated: 2022/05/30 09:33:55 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			ans;
	long		tmp;
	size_t		i;
	int			flag_min;

	ans = 0;
	tmp = 0;
	i = 0;
	flag_min = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag_min = -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		tmp = tmp * 10 + str[i] - '0';
		i++;
	}
	ans = (int)tmp * flag_min;
	return (ans);
}
