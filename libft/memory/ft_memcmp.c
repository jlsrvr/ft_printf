/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:12:42 by jrivoire          #+#    #+#             */
/*   Updated: 2020/11/30 22:15:31 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t index;

	if (n <= 0)
		return (0);
	index = -1;
	while (++index < n)
	{
		if (((unsigned char*)s1)[index] != ((unsigned char*)s2)[index])
			return (((unsigned char*)s1)[index] - ((unsigned char*)s2)[index]);
	}
	return (0);
}
