/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:24:55 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/25 13:54:14 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*g_base_10 = "0123456789";

char	*fill_start(t_specs specs, size_t len_num, int neg)
{
	char *str;
	char *temp;
	int size;

	if (specs.precision != -1)
	{
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
		if (size > 0 && !specs.right_pad)
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
	else
	{
		str = (neg ? ft_strdup("-") : ft_strdup(""));
		size = specs.min_f_width - len_num - ft_strlen(str);
		if (size > 0 && !specs.right_pad)
		{
			temp = malloc(sizeof(*temp) * (size + 1));
			if (!temp)
				return (oneline_free(str));
			temp[size] = 0;
			if (specs.zero_pad)
			{
				while (--size >= 0)
					temp[size] = filler(specs);
				string_writer(&str, temp);
			}
			else
			{
				while (--size >= 0)
					temp[size] = filler(specs);
				string_writer(&temp, str);
				return (temp);
			}
		}
		return (str);
	}
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

char	*int_converter(t_specs specs, int nbr)
{
	unsigned int	n;
	char			*my_string;
	char			*temp_str;
	int				neg;

	neg = (nbr < 0) ? 1 : 0;
	n = neg ? -nbr : nbr;
	if (n == 0 && specs.precision == 0)
		temp_str = ft_strdup("");
	else
		temp_str = ft_uitoa_base(n, g_base_10);
	if (!temp_str)
		return (NULL);
	my_string = fill_start(specs, ft_strlen(temp_str), neg);
	if (!my_string)
		return (oneline_free(temp_str));
	string_writer(&my_string, temp_str);
	if (!my_string)
		return (NULL);
	temp_str = fill_end(specs, ft_strlen(my_string));
	if (!temp_str)
		return (oneline_free(my_string));
	string_writer(&my_string, temp_str);
	return (my_string);
}
