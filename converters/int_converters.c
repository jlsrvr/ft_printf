/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:38:47 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/25 23:11:05 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*hexa_converter(t_specs specs, int c)
{
	char			*base_x;
	unsigned int	u_int;

	u_int = (unsigned int)c;
	if (specs.format == 'x')
		base_x = "0123456789abcdef";
	else
		base_x = "0123456789ABCDEF";
	return (base_converter(specs, u_int, base_x));
}

char	*unsigned_converter(t_specs specs, int c)
{
	char			*base10;
	unsigned int	u_int;

	base10 = "0123456789";
	u_int = (unsigned int)c;
	return (base_converter(specs, u_int, base10));
}

char	*signed_converter(t_specs specs, int c)
{
	char			*base10;

	base10 = "0123456789";
	return (base_converter(specs, c, base10));
}
