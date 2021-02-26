/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptn_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:06:22 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/26 18:45:55 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*g_hexa_base = "0123456789abcdef";

static void	fill_temp(char **temp, int size, char filler)
{
	(*temp)[size] = 0;
	while (--size >= 0)
		(*temp)[size] = filler;
}

static char	*fill_start_precision(t_specs specs, size_t len_num, char *str)
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

static char	*fill_start_no_precision(t_specs specs, size_t len_num, char *str)
{
	int		size;
	char	*temp;

	size = specs.min_f_width - len_num - ft_strlen(str);
	if (size > 0 && !specs.right_pad)
	{
		temp = malloc(sizeof(*temp) * (size + 1));
		if (!temp)
			return (oneline_free(str));
		temp[size] = 0;
		while (--size >= 0)
			temp[size] = filler(specs);
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

static char	*fill_start(t_specs specs, size_t len_num)
{
	char *str;

	str = ft_strdup("0x");
	if (specs.precision != -1)
		str = fill_start_precision(specs, len_num, str);
	else
		str = fill_start_no_precision(specs, len_num, str);
	return (str);
}

void		ptn_converter(t_specs specs, uintmax_t nbr, int *count)
{
	char			*my_string;
	char			*temp_str;

	if (nbr == 0 && specs.precision == 0)
		temp_str = ft_strdup("");
	else
		temp_str = ft_uitoa_base(nbr, g_hexa_base);
	if (!temp_str)
		return ;
	my_string = fill_start(specs, ft_strlen(temp_str));
	if (!my_string)
	{
		free(temp_str);
		return ;
	}
	if (!string_writer(&my_string, temp_str))
		return ;
	temp_str = fill_end(specs, ft_strlen(my_string));
	if (!temp_str)
	{
		free(my_string);
		return ;
	}
	if (!string_writer(&my_string, temp_str))
		return ;
	*count += ft_strlen(my_string);
	ft_putstr_fd(my_string, 1);
	free(my_string);
}
