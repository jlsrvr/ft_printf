/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:30:08 by jrivoire          #+#    #+#             */
/*   Updated: 2021/03/01 12:41:15 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			parse_digit(char **string)
{
	char	*digit_str;
	int		result;

	result = 0;
	while (ft_isdigit((*string)[result]))
		result++;
	digit_str = ft_substr(*string, 0, result);
	*string = (*string) + result;
	result = ft_atoi(digit_str);
	free(digit_str);
	return (result);
}

static void			check_min_f_width(t_specs *specs,
									char **string, va_list *arguments)
{
	int		value;

	value = 0;
	while (ft_isdigit(**string) || **string == '*')
	{
		if (**string == '*')
		{
			value = va_arg(*arguments, int);
			if (value < 0)
			{
				specs->min_f_width = (value * -1);
				specs->right_pad = 1;
			}
			else
				specs->min_f_width = value;
			(*string)++;
		}
		else
			specs->min_f_width = parse_digit(string);
	}
}

static void			check_precision(t_specs *specs,
									char **string, va_list *arguments)
{
	int value;

	value = 0;
	if (**string == '.')
	{
		(*string)++;
		if (is_format(**string))
			specs->precision = 0;
		while (ft_isdigit(**string) || **string == '*')
		{
			if (**string == '*')
			{
				value = va_arg(*arguments, int);
				if (value >= 0)
					specs->precision = value;
				(*string)++;
			}
			else
				specs->precision = parse_digit(string);
		}
	}
}

t_specs				conversion_parser(char **string, va_list *arguments)
{
	t_specs specs;

	specs = initialize_specs();
	while ((**string == '0' || **string == '-') && *string)
	{
		if (**string == '0')
			specs.zero_pad = 1;
		if (**string == '-')
			specs.right_pad = 1;
		(*string)++;
	}
	check_min_f_width(&specs, string, arguments);
	check_precision(&specs, string, arguments);
	if (is_format(**string))
	{
		specs.format = **string;
		(*string)++;
		return (specs);
	}
	specs.valid = 0;
	return (specs);
}
