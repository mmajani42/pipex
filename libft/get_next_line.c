/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:21:39 by mmajani           #+#    #+#             */
/*   Updated: 2022/05/09 08:03:51 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 10

char	*my_join(char *line, char *buff)
{
	int		i;
	int		l_len;
	int		b_len;
	char	*newline;

	l_len = custom_len(line, 1);
	b_len = custom_len(buff, 0);
	if (!b_len)
		b_len = custom_len(buff, 1);
	if (l_len + b_len <= 0)
		return (NULL);
	newline = malloc(sizeof(char) * (l_len + b_len + 1));
	i = -1;
	while (line && line[++i])
		newline[i] = line[i];
	i = 0;
	while (i < b_len)
	{
		newline[i + l_len] = buff[i];
		i++;
	}
	newline[l_len + i] = '\0';
	free(line);
	return (newline);
}

void	keep_buffer_rest(char *buffer)
{
	char	*mem;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mem = ft_strdup(buffer);
	ft_bzero(buffer, BUFFER_SIZE);
	while (mem[i] && mem[i - 1] != '\n')
		i++;
	while (mem[i])
		buffer[j++] = mem[i++];
	free(mem);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1] = {0};

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		line = my_join(line, buffer);
		if (buffer[0] != '\0' && custom_len(buffer, 0))
		{
			keep_buffer_rest(buffer);
			return (line);
		}
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
	}
	return (line);
}
