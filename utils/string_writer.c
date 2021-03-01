/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_writer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:30:29 by jrivoire          #+#    #+#             */
/*   Updated: 2021/03/01 12:42:28 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string_writer(char **dest, char *to_add)
{
	char *temp;

	temp = *dest;
	*dest = ft_strjoin(*dest, to_add);
	free(to_add);
	free(temp);
	if (!(*dest))
		return (0);
	return (1);
}
