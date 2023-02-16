/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:02:41 by mmajani           #+#    #+#             */
/*   Updated: 2022/03/02 11:05:20 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	custom_len(const char *str, int subfunction)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (subfunction == 0)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i + 1);
			i++;
		}
		return (0);
	}
	else if (subfunction == 1)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (!dst && !src)
		return (0);
	tmp = (unsigned char *)dst;
	while (n-- > 0)
		*(tmp++) = *(unsigned char *)src++;
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;

	if (src == dst || len == 0)
		return (dst);
	tmp = (unsigned char *)dst;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		while (len-- > 0)
			*(tmp + len) = *((unsigned char *)src + len);
	return (dst);
}
