/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:24:55 by jrivoire          #+#    #+#             */
/*   Updated: 2021/03/01 12:43:01 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_temp(char **temp, int size, char filler)
{
	(*temp)[size] = 0;
	while (--size >= 0)
		(*temp)[size] = filler;
}

char	*fill_start_precision(t_specs specs, size_t len_num, char *str)
{
	int		size;
	char	*temp;

	size = specs.precision - len_num;
	if (size > 0)
	{
		temp = malloc(sizeof(*temp) * (size + 1));
		if (!temp)
			return (oneline_free(str));
		fill_temp(&temp, size, '0');
		if (!string_writer(&str, temp))
			return (NULL);
	}
	size = specs.min_f_width - len_num - ft_strlen(str);
	if (size > 0 && !specs.right_pad)
	{
		temp = malloc(sizeof(*temp) * (size + 1));
		if (!temp)
			return (oneline_free(str));
		fill_temp(&temp, size, filler(specs));
		if (!string_writer(&temp, str))
			return (NULL);
		return (temp);
	}
	return (str);
}

char	*fill_start_no_precision(t_specs specs, size_t len_num, char *str)
{
	int		size;
	char	*temp;

	size = specs.min_f_width - len_num - ft_strlen(str);
	if (size > 0 && !specs.right_pad)
	{
		temp = malloc(sizeof(*temp) * (size + 1));
		if (!temp)
			return (oneline_free(str));
		fill_temp(&temp, size, filler(specs));
		if (specs.zero_pad)
		{
			if (!string_writer(&str, temp))
				return (NULL);
		}
		else
		{
			if (!string_writer(&temp, str))
				return (NULL);
			return (temp);
		}
	}
	return (str);
}

char	*fill_start(t_specs specs, size_t len_num, int neg)
{
	char *str;

	str = (neg ? ft_strdup("-") : ft_strdup(""));
	if (specs.precision == -1)
		str = fill_start_no_precision(specs, len_num, str);
	else
		str = fill_start_precision(specs, len_num, str);
	return (str);
}

char	*base_converter(t_specs specs, intmax_t nbr, char *base)
{
	uintmax_t		n;
	char			*my_string;
	char			*temp_str;
	int				neg;

	neg = ((nbr < 0) ? 1 : 0);
	n = (neg ? -nbr : nbr);
	if (n == 0 && specs.precision == 0)
		temp_str = ft_strdup("");
	else
		temp_str = ft_uitoa_base(n, base);
	if (!temp_str)
		return (NULL);
	my_string = fill_start(specs, ft_strlen(temp_str), neg);
	if (!my_string)
		return (oneline_free(temp_str));
	if (!string_writer(&my_string, temp_str))
		return (NULL);
	temp_str = fill_end(specs, ft_strlen(my_string));
	if (!temp_str)
		return (oneline_free(my_string));
	if (!string_writer(&my_string, temp_str))
		return (NULL);
	return (my_string);
}
