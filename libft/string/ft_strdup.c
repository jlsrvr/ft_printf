/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:53:00 by jrivoire          #+#    #+#             */
/*   Updated: 2020/11/30 20:53:26 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		index;

	if (!(dest = malloc(sizeof(char) * (ft_strlen((char*)src) + 1))))
		return (NULL);
	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	if (src[index] == '\0')
		dest[index] = 0;
	return (dest);
}
