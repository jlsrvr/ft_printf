/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:12:18 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/26 17:40:20 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "utils.h"

typedef	struct		s_specs
{
	int				valid;
	int				zero_pad;
	int				right_pad;
	int				min_f_width;
	int				precision;
	char			format;
}					t_specs;

char				*char_converter(t_specs specs, int c);
char				*fill_end(t_specs specs, size_t len_str);
char				*base_converter(t_specs specs, intmax_t c, char *base);
char				*hexa_converter(t_specs specs, int c);
char				*oneline_free(char *to_free);
char				*ptn_converter(t_specs specs, uintmax_t c);
char				*signed_converter(t_specs specs, int c);
char				*str_converter(t_specs specs, char *str);
char				*unsigned_converter(t_specs specs, int c);
char				filler(t_specs spec);
int					converting_function(t_specs specs, va_list *arguments,
											char **dest);
int					is_format(char c);
int					string_writer(char **dest, char *to_add);
int                 ft_printf(const char *string, ...);
t_specs				conversion_parser(char **string, va_list *arguments);
t_specs				initialize_specs(void);
void				string_parser(char **string, va_list *arguments,
									int *count);
#endif
