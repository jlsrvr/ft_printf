/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:21:55 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/23 11:36:31 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *(*g_converters[7])(t_specs specs, int number) = {char_converter/*, dec_converter, int_converter, un_int_converter, hexa_converter, u_hexa_converter*/};

int	converting_function(t_specs specs, va_list *arguments, char **dest)
{
	int		f_index;
	char	*converted;

	if (!specs.valid)
		return (0);
	f_index = (is_format(specs.format) - 4);
	if (f_index < 0)
	{
		if (specs.format == '%')
			converted = (*g_converters[0])(specs, '%');
		else
			converted = str_converter(specs, va_arg(*arguments, char *));
	}
	else
		converted = (*g_converters[f_index])(specs, va_arg(*arguments, int));
	if (!converted)
		return (0);
	string_writer(dest, converted);
	return (1);
}
