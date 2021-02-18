/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:57:28 by jrivoire          #+#    #+#             */
/*   Updated: 2020/12/14 22:52:34 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *csrc;
	char *cdest;

	csrc = (char*)src;
	cdest = (char*)dest;
	if (!dest && !src)
		return (NULL);
	while ((int)--len >= 0)
		if (csrc < cdest)
			*(cdest + len) = *(csrc + len);
		else
			*(cdest++) = *(csrc++);
	return (dest);
}
