/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoe <tomoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:04:11 by tomoe             #+#    #+#             */
/*   Updated: 2022/05/25 20:27:18 by tkawakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ans;

	if (nmemb == 0)
		nmemb = 1;
	if (SIZE_MAX / nmemb < size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ans = malloc(nmemb * size);
	if (!ans)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(ans, nmemb * size);
	return (ans);
}
