/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:38:47 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/25 20:05:17 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*unsigned_converter(t_specs specs, int c)
{
	char			*base10;
	unsigned int	u_int;

	base10 = "0123456789";
	u_int = (unsigned int)c;
	return (base_converter(specs, u_int, base10));
}
