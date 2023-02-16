/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:57:16 by mmajani           #+#    #+#             */
/*   Updated: 2022/04/29 10:19:08 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	long	total;
	int		neg;

	if (!*str || str[0] == '\n')
		return (0);
	total = 0;
	neg = 1;
	while (ft_strchr("\t\n\r\v\f ", *str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && ft_isdigit(*str) == 1)
	{
		total *= 10;
		total += (*str - '0');
		str++;
	}
	return ((total * neg));
}
