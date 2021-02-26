/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 23:26:29 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/26 17:43:05 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	char	*string;
	int		count;

	count = 0;
	if (!ft_strchr(str, '%'))
	{
		count = ft_strlen(str);
		ft_putstr_fd(str, 1);
		return (count);
	}
	string = ft_strdup(str);
	if (!string)
		return (0);
	va_start(arguments, str);
	string_parser(&string, &arguments, &count);
	va_end(arguments);
	return (count);
}
