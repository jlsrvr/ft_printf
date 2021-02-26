/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:21:55 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/26 17:57:56 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void (*g_converters[7])(t_specs specs, int number) = {char_converter,
	signed_converter, signed_converter, unsigned_converter,
	hexa_converter, hexa_converter};

void	converting_function(t_specs specs, va_list *arguments, int *count)
{
	int		f_index;

	if (!specs.valid)
		return ;
	f_index = (is_format(specs.format) - 4);
	if (f_index < 0)
	{
		if (specs.format == '%')
			(*g_converters[0])(specs, '%');
		else if (specs.format == 'p')
			ptn_converter(specs, va_arg(*arguments, uintmax_t));
		else
			str_converter(specs, va_arg(*arguments, char *));
	}
	else
		(*g_converters[f_index])(specs, va_arg(*arguments, int));
	return ;
}
