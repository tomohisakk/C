/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomo <tomo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:04:11 by tomoe             #+#    #+#             */
/*   Updated: 2022/06/08 17:12:12 by tomo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ans;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (SIZE_MAX / nmemb < size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ans = malloc(nmemb * size);
	if (!ans)
		return (NULL);
	ft_bzero(ans, nmemb * size);
	return (ans);
}
