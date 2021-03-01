/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:58:19 by jrivoire          #+#    #+#             */
/*   Updated: 2021/03/01 12:43:12 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		calculate_len_str(t_specs specs, char *str, int *len_str)
{
	if (specs.precision != -1 && specs.precision < (int)ft_strlen(str))
		*len_str = specs.precision;
	else
		*len_str = (int)ft_strlen(str);
}

void			right_pad_fill(char **my_str, char *str,
		int width, t_specs specs)
{
	int index;
	int len_str;

	index = 0;
	calculate_len_str(specs, str, &len_str);
	while (str[index] && index < len_str)
	{
		(*my_str)[index] = str[index];
		index++;
	}
	while (index < width)
		(*my_str)[index++] = filler(specs);
	(*my_str)[index] = 0;
}

void			left_pad_fill(char **my_str, char *str,
		int padding, t_specs specs)
{
	int index;
	int len_str;

	index = 0;
	calculate_len_str(specs, str, &len_str);
	while (padding-- > 0)
		(*my_str)[index++] = filler(specs);
	padding = 0;
	while (str[padding] && padding < len_str)
		(*my_str)[index++] = str[padding++];
	(*my_str)[index] = 0;
}

void			str_converter(t_specs specs, char *str, int *count)
{
	char	*my_str;
	int		width;
	int		padding;
	int		len_str;

	if (!str)
		str = "(null)";
	calculate_len_str(specs, str, &len_str);
	padding = specs.min_f_width - len_str;
	width = (padding < 0 ? len_str : specs.min_f_width);
	my_str = malloc(sizeof(*my_str) * (width + 1));
	if (!my_str)
		return ;
	if (specs.right_pad)
		right_pad_fill(&my_str, str, width, specs);
	else
		left_pad_fill(&my_str, str, padding, specs);
	*count += ft_strlen(my_str);
	ft_putstr_fd(my_str, 1);
	free(my_str);
}
