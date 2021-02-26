/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:58:19 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/26 16:08:46 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		fill_my_char(char **my_char, char filler,
								int min_width, int right_pad)
{
	char	*str;
	int		index;

	str = *my_char;
	index = 1;
	if (right_pad)
	{
		while (index <= min_width)
			str[index++] = filler;
	}
	else
	{
		while (min_width >= 0)
			str[min_width--] = filler;
	}
	return ;
}

char			*char_converter(t_specs specs, int c)
{
	char	*my_char;
	char	con_c;
	int		min_width;

	con_c = (unsigned char)c;
	min_width = (specs.min_f_width > 0 ? specs.min_f_width : 1);
	my_char = malloc(sizeof(*my_char) * (min_width + 1));
	if (!my_char)
		return (NULL);
	my_char[min_width--] = 0;
	if (specs.right_pad)
	{
		my_char[0] = con_c;
		fill_my_char(&my_char, filler(specs), min_width, specs.right_pad);
	}
	else
	{
		my_char[(min_width--)] = con_c;
		fill_my_char(&my_char, filler(specs), min_width, specs.right_pad);
	}
	return (my_char);
}
