/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:12:18 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/19 16:50:20 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef	struct		s_specs
{
	int	zero_pad;
	int	right_pad;
	int	min_f_width;
	int	precision;
}					t_specs;

char	*char_converter(t_specs specs, int c);
char	*str_converter(t_specs specs, char *str);
#endif
