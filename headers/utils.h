/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:26:22 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/26 09:57:02 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

char			*ft_uitoa_base(uintmax_t n, char *base);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_atoi(const char *str);
int				ft_isdigit(int c);

size_t			ft_strlen(char const *str);

void			ft_putstr_fd(char *str, int fd);
#endif
