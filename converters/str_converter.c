/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:58:19 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/19 18:16:21 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		fill_my_str(char **my_str, char filler,
		int min_width, int right_pad)
{
	char	*str;
	int		index;

	str = *my_str;
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

char			*str_converter(t_specs specs, char *str)
{
	char	*my_str;
	char	filler;
	int		width;
	int		padding;
	int		index;

	if (!str)
		return (ft_strdup("(null)"));
	filler = (specs.zero_pad ? '0' : ' ');
	filler = (specs.right_pad ? ' ' : filler);
	padding = specs.min_f_width - ft_strlen(str);
	width = (padding < 0 ? ft_strlen(str) : specs.min_f_width);
	width = specs.precision < 0 ? width : specs.precision;
	my_str = malloc(sizeof(*my_str) * (width + 1));
	if (!my_str)
		return (NULL);
	index = 0;
	if (specs.right_pad)
	{
		while (str[index])
		{
			my_str[index] = str[index];
			index++;
		}
		while (index < width)
			my_str[index++] = filler;
	}
	else
	{
		while (padding-- > 0)
			my_str[index++] = filler;
		padding = 0;
		while (str[padding])
			my_str[index++] = str[padding++];
	}
	my_str[index] = 0;
	/*if (specs.right_pad)
	  {
	  my_char[0] = con_c;
	  fill_my_char(&my_char, c, min_width, specs.right_pad);
	  }
	  else
	  {
	  my_char[(min_width--)] = con_c;
	  fill_my_char(&my_char, c, min_width, specs.right_pad);
	  }*/
	return (my_str);
}
