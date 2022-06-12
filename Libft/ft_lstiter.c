/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:05:07 by tomo              #+#    #+#             */
/*   Updated: 2022/06/13 00:08:35 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp_lst;

	if (lst)
	{
		tmp_lst = lst;
		while (tmp_lst)
		{
			f(tmp_lst->content);
			tmp_lst = tmp_lst->next;
		}
	}
}
