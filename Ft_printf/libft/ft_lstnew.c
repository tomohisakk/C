/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:37:52 by tomo              #+#    #+#             */
/*   Updated: 2022/06/12 23:59:58 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*parameter;

	parameter = (t_list *)malloc(sizeof(t_list));
	if (!parameter)
		return (NULL);
	parameter->content = content;
	parameter->next = NULL;
	return (parameter);
}
