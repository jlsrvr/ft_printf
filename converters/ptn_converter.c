/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptn_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:06:22 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/24 13:49:47 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hexa_base = "0123456789abcdef";

static char			filler(t_specs specs)
  {
  char filler;

  filler = (specs.zero_pad ? '0' : ' ');
  filler = (specs.right_pad ? ' ' : filler);
  return (filler);
  }

char	*ptn_converter(t_specs specs, uintmax_t ptn)
{
	char *hexa_trans;
	char *my_string;
	char *temp;
	int padding;

	my_string = ft_strdup("0x");
	if (ptn == 0 && specs.precision == 0)
		hexa_trans = ft_strdup("");
	else
		hexa_trans = ft_uitoa_base(ptn, hexa_base);
	if (!hexa_trans)
		return (NULL);
	padding = specs.min_f_width - (ft_strlen(hexa_trans) + 2);
	if (specs.right_pad || padding <= 0)
		string_writer(&my_string, hexa_trans);
	if (padding > 0 && !specs.right_pad && !specs.zero_pad)
	{
		string_writer(&my_string, hexa_trans);
		temp = my_string;
		if (!(my_string = malloc(sizeof(*my_string) * (padding + 1))))
		{
			free(temp);
			return (NULL);
		}
		else
		{
			my_string[padding] = 0;
			while (--padding >= 0)
				my_string[padding] = ' ';
			string_writer(&my_string, temp);
		}
	}
	if (padding > 0 && (specs.right_pad || specs.zero_pad))
	{
		temp = malloc(sizeof(*my_string) * (padding + 1));
		if (!temp)
		{
			free(my_string);
			return (NULL);
		}
		else
		{
			temp[padding] = 0;
			while (--padding >=0)
				temp[padding] = filler(specs);
			string_writer(&my_string, temp);
			if (!specs.right_pad)
				string_writer(&my_string, hexa_trans);
		}
	}
	return (my_string);
}
