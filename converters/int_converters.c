/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:38:47 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/26 18:44:20 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	hexa_converter(t_specs specs, int c, int *count)
{
	char			*base_x;
	char			*my_str;
	unsigned int	u_int;

	u_int = (unsigned int)c;
	if (specs.format == 'x')
		base_x = "0123456789abcdef";
	else
		base_x = "0123456789ABCDEF";
	my_str = base_converter(specs, u_int, base_x);
	*count += ft_strlen(my_str);
	ft_putstr_fd(my_str, 1);
	free(my_str);
}

void	unsigned_converter(t_specs specs, int c, int *count)
{
	char			*base10;
	char			*my_str;
	unsigned int	u_int;

	base10 = "0123456789";
	u_int = (unsigned int)c;
	my_str = base_converter(specs, u_int, base10);
	*count += ft_strlen(my_str);
	ft_putstr_fd(my_str, 1);
	free(my_str);
}

void	signed_converter(t_specs specs, int c, int *count)
{
	char			*base10;
	char			*my_str;

	base10 = "0123456789";
	my_str = base_converter(specs, c, base10);
	*count += ft_strlen(my_str);
	ft_putstr_fd(my_str, 1);
	free(my_str);
}
