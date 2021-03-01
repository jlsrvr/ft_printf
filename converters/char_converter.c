/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:58:19 by jrivoire          #+#    #+#             */
/*   Updated: 2021/03/01 12:43:23 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_my_char(char filler, int min_width, int *count)
{
	int		index;

	index = 1;
	while (index++ <= min_width)
	{
		ft_putchar_fd(filler, 1);
		(*count)++;
	}
}

void			char_converter(t_specs specs, int c, int *count)
{
	char	con_c;
	int		min_width;

	con_c = (unsigned char)c;
	min_width = specs.min_f_width - 1;
	if (specs.right_pad)
	{
		ft_putchar_fd(con_c, 1);
		(*count)++;
		fill_my_char(filler(specs), min_width, count);
	}
	else
	{
		fill_my_char(filler(specs), min_width, count);
		ft_putchar_fd(con_c, 1);
		(*count)++;
	}
	return ;
}
