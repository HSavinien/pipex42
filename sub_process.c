/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:54:02 by tmongell          #+#    #+#             */
/*   Updated: 2022/07/05 19:06:10 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	**path;
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) && env[i])
		i ++;
	if (!env)
		error ("environment variable PATH can't be located");
	path = ft_split(ft_strchr(env[i], '=') + 1, ':');
	if (!path)
		error("problem with env var PATH");
	return (path);
}

void	do_cmd(char	*fct, char **env)
{
	char	**path;
	char	*cmd_path;
	char	**args;
	int		pid;
	int		i;

	pid = fork();
	if (!pid)
	{
		fct = extract_args(fct, &args);
		path = get_path(env);
		i = 0;
		execve(fct, args, env);
		while (path[i])
		{
			cmd_path = ft_strjoin(path[i ++], "/");
			cmd_path = ft_strjoin(cmd_path, fct);
			execve(cmd_path, args, env);
			free(cmd_path);
		}
		error("comande not found");
	}
	else
		waitpid(pid, &i, 0);
}
