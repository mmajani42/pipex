/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:04:47 by mmajani           #+#    #+#             */
/*   Updated: 2021/11/26 17:26:31 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
