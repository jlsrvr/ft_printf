/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:40:52 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/26 11:18:47 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	string_parser(char **string, va_list *arguments, char **dest)
{
	char	*temp;
	char	*to_free;
	t_specs specs;

	if (!ft_strchr(*string, '%'))
		return (string_writer(dest, *string));
	to_free = *string;
	while (**string)
	{
		if (**string == '%')
		{
			(*string)++;
			specs = conversion_parser(string, arguments);
			converting_function(specs, arguments, dest);
		}
		else
		{
			temp = ft_substr(*string, 0, 1);
			string_writer(dest, temp);
			(*string)++;
		}
	}
	free(to_free);
	return (1);
}
