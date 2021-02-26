/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 23:26:29 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/26 18:41:50 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	char	*string;
	char	*to_free;
	int		count;

	string = ft_strdup(str);
	if (!string)
		return (0);
	to_free = string;
	count = 0;
	if (!ft_strchr(string, '%'))
	{
		count = ft_strlen(string);
		ft_putstr_fd(string, 1);
		free(to_free);
		return (count);
	}
	va_start(arguments, str);
	string_parser(&string, &arguments, &count);
	va_end(arguments);
	return (count);
}
