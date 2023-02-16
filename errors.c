/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:01:11 by mmajani           #+#    #+#             */
/*   Updated: 2022/10/10 15:42:37 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	my_perror(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, ": ", 3);
	perror("");
}

int	check_direct_input_path(char *cmd)
{
	if (cmd[0] == '/' || cmd[1] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (1);
		else
		{
			my_perror(cmd);
			exit(84);
		}
	}
	return (-1);
}

int	check_fork(int pid)
{
	if (pid == -1)
	{
		write(1, "fork failed\n", 13);
		exit(84);
	}
	return (1);
}
