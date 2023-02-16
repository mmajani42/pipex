/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:58:11 by mmajani           #+#    #+#             */
/*   Updated: 2022/10/10 14:02:30 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cp_cmd1(t_data *data, char **av, char **envp)
{
	char	*new_path;

	new_path = NULL;
	close(data->tube[0]);
	data->infile = open(av[1], O_RDONLY);
	if (data->infile == -1)
	{
		my_perror(av[1]);
		exit(84);
	}
	data->cmd_args = ft_split(av[2], ' ');
	new_path = construct_path(data, data->cmd_args[0], envp);
	dup2(data->infile, STDIN_FILENO);
	close(data->infile);
	dup2(data->tube[1], STDOUT_FILENO);
	close(data->tube[1]);
	execve(new_path, data->cmd_args, envp);
	if (new_path)
		free(new_path);
	exit(1);
}

void	cp_cmd2(t_data *data, char **av, char **envp)
{
	char	*new_path;

	new_path = NULL;
	close(data->tube[1]);
	data->outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		my_perror(av[4]);
		exit(84);
	}
	data->cmd_args = ft_split(av[3], ' ');
	new_path = construct_path(data, data->cmd_args[0], envp);
	dup2(data->outfile, STDOUT_FILENO);
	close(data->outfile);
	dup2(data->tube[0], STDIN_FILENO);
	close(data->tube[0]);
	execve(new_path, data->cmd_args, envp);
	if (new_path)
		free(new_path);
	exit(2);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		pid1;
	int		pid2;

	if (ac != 5)
	{
		write(1, "WRONG ARG NB\n", 14);
		return (10);
	}
	if (pipe(data.tube) == -1)
		return (1);
	pid1 = fork();
	check_fork(pid1);
	if (pid1 == 0)
		cp_cmd1(&data, av, envp);
	pid2 = fork();
	check_fork(pid2);
	if (pid2 == 0)
		cp_cmd2(&data, av, envp);
	close(data.tube[0]);
	close(data.tube[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
