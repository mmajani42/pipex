/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexbonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:58:11 by mmajani           #+#    #+#             */
/*   Updated: 2023/02/23 10:37:37 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_data *data, int ac, char **av)
{
	data->infile = open(av[1], O_RDONLY);
	if (data->infile == -1)
	{
		my_perror(av[1]);
		exit(84);
	}
	data->outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		my_perror(av[4]);
		exit(84);
	}
	dup2(data->infile, STDIN);
	dup2(data->outfile, STDOUT);
}

void	my_exec(t_data *data, char **av, char **envp, int i)
{
	char *new_path;

	new_path = NULL;
	data->cmd_args = ft_split(av[i], ' ');
	new_path = construct_path(data, data->cmd_args[0], envp);
	execve(new_path, data->cmd_args, envp);
	if (new_path)
		free(new_path);
	exit(10);
}

void	redirect_fds(t_data *data, char **av, char **envp, int i)
{
	pid_t pid;

	if (pipe(data->tube) == -1)
		return ;
	pid = fork();
	if (pid)
	{
		close(data->tube[1]);
		dup2(data->tube[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(data->tube[0]);
		dup2(data->tube[1], STDOUT);
		if (data->infile == STDIN)
			exit(1);
		else
			my_exec(data, av, envp, i);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		i;

	i = 2;
	if (ac < 5)
	{
		write(1, "WRONG ARG NB\n", 14);
		return (10);
	}
	i = 3;
	open_files(&data, ac, av);
	redirect_fds(&data, av, envp, 2);
	while (i < ac - 2)
		redirect_fds(&data, av, envp, i++);
	my_exec(&data, av, envp, i);
	return (1);
}
