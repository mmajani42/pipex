/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:59:32 by mmajani           #+#    #+#             */
/*   Updated: 2022/10/06 12:49:20 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_paths(t_data *data, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			data->paths = ft_split(*(&envp[i]) + 5, ':');
			return (1);
		}
		i++;
	}
	return (-1);
}
									//	^^^
									//	|||
									//	|||
									//*(&envp[i]) + 5 is used to skip the PATH=

static void	cmd_not_found_exit(char *cmd)
{
	write(1, cmd, ft_strlen(cmd));
	write(1, ": command not found\n", 21);
}

char	*construct_path(t_data *data, char *cmd, char **envp)
{
	int		i;
	char	*new_path;
	char	*new_cmd;

	if (check_direct_input_path(cmd) == 1)
		return (cmd);
	i = 0;
	new_cmd = ft_strjoin("/", cmd);
	new_path = NULL;
	get_paths(data, envp);
	while (data->paths[i])
	{
		if (new_path)
			free(new_path);
		new_path = ft_strjoin(data->paths[i], new_cmd);
		if (access(new_path, X_OK) == 0)
		{
			free(new_cmd);
			return (new_path);
		}
		i++;
	}
	cmd_not_found_exit(cmd);
	return (NULL);
}
