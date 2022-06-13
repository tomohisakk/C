/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:08:49 by tomo              #+#    #+#             */
/*   Updated: 2022/06/13 00:30:24 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*next_lst;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (NULL);
	next_lst = new_list;
	lst = lst->next;
	while (!lst)
	{
		next_lst->next = ft_lstnew(f(lst->content));
		if (next_lst->next == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		next_lst = next_lst->next;
		lst = lst->next;
	}
	return (new_list);
}
