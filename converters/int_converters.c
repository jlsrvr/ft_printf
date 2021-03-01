/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:38:47 by jrivoire          #+#    #+#             */
/*   Updated: 2021/03/01 10:08:28 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*g_base_ten = "0123456789";

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
	char			*my_str;
	unsigned int	u_int;

	u_int = (unsigned int)c;
	my_str = base_converter(specs, u_int, g_base_ten);
	*count += ft_strlen(my_str);
	ft_putstr_fd(my_str, 1);
	free(my_str);
}

void	signed_converter(t_specs specs, int c, int *count)
{
	char			*my_str;

	my_str = base_converter(specs, c, g_base_ten);
	*count += ft_strlen(my_str);
	ft_putstr_fd(my_str, 1);
	free(my_str);
}
