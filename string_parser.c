/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:40:52 by jrivoire          #+#    #+#             */
/*   Updated: 2021/03/01 12:41:35 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_parser(char **string, va_list *arguments, int *count)
{
	char	*to_free;
	t_specs specs;

	to_free = *string;
	while (**string)
	{
		if (**string == '%')
		{
			(*string)++;
			specs = conversion_parser(string, arguments);
			converting_function(specs, arguments, count);
		}
		else
		{
			(*count)++;
			ft_putchar_fd(**string, 1);
			(*string)++;
		}
	}
	free(to_free);
}
