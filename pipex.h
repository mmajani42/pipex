/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:01:39 by mmajani           #+#    #+#             */
/*   Updated: 2023/02/23 10:00:06 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define INFILE 0
# define OUTFILE 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_data
{
	char	**paths;
	char	**cmd_args;
	char	**cmd1_args;
	int		tube[2];
	int		infile;
	int		outfile;
	int		id;
}			t_data;

int		check_fork(int pid);
int		check_direct_input_path(char *cmd);
char	*construct_path(t_data *data, char *cmd, char **envp);
void	my_perror(char *str);

#endif
