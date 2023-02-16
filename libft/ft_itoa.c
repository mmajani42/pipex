/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:35:51 by mmajani           #+#    #+#             */
/*   Updated: 2022/01/10 10:29:05 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*do_algorithm(int number, int x, int neg)
{
	int		tmp;
	char	*number_string;

	tmp = number;
	while (tmp >= 10)
	{
		tmp /= 10;
		x++;
	}
	number_string = ft_calloc(x + 2, sizeof(char));
	if (!number_string)
		return (NULL);
	while (number)
	{
		number_string[x--] = (number % 10) + '0';
		number /= 10;
	}
	if (neg)
		number_string[0] = '-';
	return (number_string);
}

char	*ft_itoa(int n)
{
	int		isneg;
	int		x;
	char	*string;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	isneg = 0;
	x = 0;
	if (n < 0)
	{
		n *= -1;
		isneg = 1;
		x = 1;
	}
	string = do_algorithm(n, x, isneg);
	if (!string)
		return (NULL);
	return (string);
}
