/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:24:55 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/24 16:45:13 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*g_base_10 = "0123456789";

char	*fill_start(t_specs specs, size_t len_num, int neg)
{
	char *str;
	char *temp;
	int size;

	size = specs.precision - len_num;
	str = (neg ? ft_strdup("-") : ft_strdup(""));
	if (size > 0)
	{
		temp = malloc(sizeof(*temp) * (size + 1));
		if (!temp)
			return (oneline_free(str));
		temp[size] = 0;
		while (--size >= 0)
			temp[size] = '0';
		string_writer(&str, temp);
	}
	size = specs.min_f_width - len_num - ft_strlen(str);
	if (size > 0)
	{
		temp = malloc(sizeof(*temp) * (size + 1));
		if (!temp)
			return (oneline_free(str));
		temp[size] = 0;
		while (--size >= 0)
			temp[size] = ' ';
		string_writer(&temp, str);
		return (temp);
	}
	return (str);
}

char	*int_converter(t_specs specs, int nbr)
{
	unsigned int n;
	char *my_string;
	char *temp_str;
	int neg;
	int len_num;

	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
		n = -nbr;
	}
	else
		n = nbr;
	temp_str = ft_uitoa_base(n, g_base_10);
	if (!temp_str)
		return (NULL);
	len_num = ft_strlen(temp_str);
	my_string = fill_start(specs, len_num, neg);
	if (!my_string)
		return (oneline_free(temp_str));
	string_writer(&my_string, temp_str);
	if (!my_string)
		return (NULL);

	return (my_string);
}
