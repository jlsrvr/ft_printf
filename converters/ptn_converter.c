/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptn_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:06:22 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/23 19:42:59 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hexa_base = "0123456789abcdef";

char	*ptn_converter(t_specs specs, unsigned int ptn)
{
	char *hexa_trans;
	char *my_string;

	my_string = ft_strdup("0x10");
	hexa_trans = ft_itoa_base(ptn, hexa_base);
	string_writer(&my_string, hexa_trans);
	return (my_string);
}
