/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:59:14 by jrivoire          #+#    #+#             */
/*   Updated: 2020/11/23 20:05:30 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	char	*dest;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(dest = malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	index = 0;
	while (*s1)
		dest[index++] = *(s1++);
	while (*s2)
		dest[index++] = *(s2++);
	dest[index] = 0;
	return (dest);
}
