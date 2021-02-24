/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptn_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:06:22 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/24 15:01:36 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*g_hexa_base = "0123456789abcdef";

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
		return (oneline_free(add_on));
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
	char	*temp;
	char	*my_string;
	size_t	hexa_len;

	if (ptn == 0 && specs.precision == 0)
		temp = ft_strdup("");
	else
		temp = ft_uitoa_base(ptn, g_hexa_base);
	if (!temp)
		return (NULL);
	hexa_len = ft_strlen(temp);
	my_string = fill_start(specs, hexa_len);
	if (!my_string)
		return (oneline_free(temp));
	string_writer(&my_string, temp);
	if (!my_string)
		return (NULL);
	temp = fill_end(specs, hexa_len);
	if (!temp)
		return (oneline_free(my_string));
	string_writer(&my_string, temp);
	return (my_string);
}
