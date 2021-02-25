/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:09:22 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/25 15:15:52 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*g_formats = "%spcdiuxX";

t_specs	initialize_specs(void)
{
	t_specs specs;

	specs.valid = 1;
	specs.zero_pad = 0;
	specs.right_pad = 0;
	specs.min_f_width = 0;
	specs.precision = -1;
	specs.format = 0;
	return (specs);
}

int		is_format(char c)
{
	int index;

	index = 0;
	while (g_formats[index])
	{
		if (g_formats[index++] == c)
			return (index);
	}
	return (0);
}

char	filler(t_specs specs)
{
	char filler;
	char zero;

	zero = '0';
	if (specs.format == 'i')
	{
		if (specs.precision != -1)
			zero = ' ';
	}
	filler = (specs.zero_pad ? zero : ' ');
	filler = (specs.right_pad ? ' ' : filler);
	return (filler);
}

char	*oneline_free(char *to_free)
{
	free(to_free);
	return (NULL);
}

char	*fill_end(t_specs specs, size_t len_int)
{
	char	*str;
	int		padding;

	padding = specs.min_f_width - len_int;
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
