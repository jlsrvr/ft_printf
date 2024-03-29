/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:27:16 by jrivoire          #+#    #+#             */
/*   Updated: 2021/04/01 11:22:33 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int		check_base(char *base)
{
	int index;
	int comp;

	index = 0;
	while (base[index])
	{
		comp = 1;
		if (base[index] == '-' || base[index] == '+')
			return (0);
		while (base[index + comp])
		{
			if (base[index] == base[index + comp])
				return (0);
			++comp;
		}
		++index;
	}
	return (1);
}

static	size_t	len_num(uintmax_t nbr, size_t basetype)
{
	size_t				len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr >= basetype)
	{
		len++;
		nbr = nbr / basetype;
	}
	return (len + 1);
}

static	void	store_num(uintmax_t nbr, char *num,
							size_t *index, char *base)
{
	size_t basetype;

	basetype = ft_strlen(base);
	if (nbr <= basetype - 1 && nbr >= 0)
		num[(*index)++] = base[nbr];
	else
	{
		store_num((nbr / basetype), num, index, base);
		store_num((nbr % basetype), num, index, base);
	}
	num[*index] = 0;
	return ;
}

char			*ft_uitoa_base(uintmax_t n, char *base)
{
	char				*num;
	size_t				index;
	size_t				basetype;

	num = NULL;
	basetype = ft_strlen(base);
	if (basetype > 1 && check_base(base))
	{
		if (!(num = malloc(sizeof(*num) * (len_num(n, basetype) + 1))))
			return (NULL);
		index = 0;
		store_num(n, num, &index, base);
	}
	return (num);
}
