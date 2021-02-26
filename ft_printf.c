/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 23:26:29 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/26 11:28:35 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	va_list	arguments;
	char	*dest;
	char	*string;
	int		count;

	string = ft_strdup(str);
	if (!string)
		return (0);
	va_start(arguments, str);
	string_parser(&string, &arguments, &dest);
	va_end(arguments);
	count = ft_strlen(dest);
	ft_putstr_fd(dest, 0);
	free(dest);
	return (count);
}