/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptn_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:06:22 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/24 14:39:54 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*g_hexa_base = "0123456789abcdef";

static char			filler(t_specs specs)
{
	char filler;

	filler = (specs.zero_pad ? '0' : ' ');
	filler = (specs.right_pad ? ' ' : filler);
	return (filler);
}

char	*fill_start(t_specs specs, size_t len_hexa)
{
	char	*str;
	char	*add_on;
	int		padding;

	add_on = ft_strdup("0x");
	if (!add_on)
		return (NULL);
	padding = specs.min_f_width - (len_hexa + 2);
	if (padding < 0 || specs.right_pad)
		return (add_on);
	str = malloc(sizeof(*str) * (padding + 1));
	if (!str)
	{
		free(add_on);
		return (NULL);
	}
	str[padding] = 0;
	while (--padding >= 0)
		str[padding] = filler(specs);
	if (specs.zero_pad)
	{
		string_writer(&add_on, str);
		return (add_on);
	}
	string_writer(&str, add_on);
	return (str);
}

char	*fill_end(t_specs specs, size_t len_hexa)
{
	char	*str;
	int		padding;

	padding = specs.min_f_width - (len_hexa + 2);
	if (padding < 0 || !specs.right_pad)
		return (ft_strdup(""));
	str = malloc(sizeof(*str) * (padding + 1));
	if (!str)
		return (NULL);
	str[padding] = 0;
	while (--padding >= 0)
		str[padding] = ' ';
	return (str);
}

char	*ptn_converter(t_specs specs, uintmax_t ptn)
{
	char	*hexa_trans;
	char	*my_string;
	size_t	hexa_len;

	if (ptn == 0 && specs.precision == 0)
		hexa_trans = ft_strdup("");
	else
		hexa_trans = ft_uitoa_base(ptn, g_hexa_base);
	if (!hexa_trans)
		return (NULL);
	hexa_len = ft_strlen(hexa_trans);
	my_string = fill_start(specs, hexa_len);
	string_writer(&my_string, hexa_trans);
	string_writer(&my_string, fill_end(specs, hexa_len));
	return (my_string);
}
