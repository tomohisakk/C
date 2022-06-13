/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:48:29 by tomo              #+#    #+#             */
/*   Updated: 2022/06/13 00:00:08 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*next_lst;
	int		count;

	next_lst = lst;
	count = 0;
	while (next_lst)
	{
		next_lst = next_lst->next;
		count++;
	}
	return (count);
}
