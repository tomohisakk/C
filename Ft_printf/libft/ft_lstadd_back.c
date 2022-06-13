/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:55:53 by tomo              #+#    #+#             */
/*   Updated: 2022/06/13 00:00:18 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end_lst;

	if (lst)
	{
		end_lst = *lst;
		if (!(*lst))
			*lst = new;
		else
		{
			while (end_lst->next)
				end_lst = end_lst->next;
			end_lst->next = new;
		}
	}
}
