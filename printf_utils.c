/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:09:22 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/22 16:28:03 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*g_formats = "cspdiuxX%";

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
			return (1);
	}
	return (0);
}
