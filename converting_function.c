/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:21:55 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/23 10:51:21 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//char *(*g_converters[7])(t_specs specs, int number) = {char_converter};

//g_converters[0] = char_converter;
//g_converters[6] = char_converter;

/*"spcdiuxX%"
converters[1] = pointeur_converter(t_specs specs, UNKNOWN)

g_converters[1] = decimal_converter
g_converters[1] = integer_converter
g_converters[1] = unsigne_decimal_converter
g_converters[1] = hexa_converter
g_converters[1] = u_hexa_converter
*/

int	converting_function(t_specs specs, va_list *arguments, char **dest)
{
	//int		f_index;
	char	*converted;

	if (!specs.valid)
		return (0);
	//f_index = (is_format(specs.format) - 1);
	//if (f_index == 0)
	converted = str_converter(specs, va_arg(*arguments, char *));
	//else
	//	converted = (*g_converters[f_index])(specs, va_arg(*arguments, int));
	string_writer(dest, converted);
	return (1);
}

