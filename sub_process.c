/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:54:02 by tmongell          #+#    #+#             */
/*   Updated: 2022/07/13 15:05:33 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	try_path(char *cmd, char *path, char **args, char **env)
{
	char	*cmd_path;

	cmd_path = ft_strjoin(path, "/");
	cmd_path = ft_strjoin(cmd_path, cmd);
	execve(cmd_path, args, env);
	free(cmd_path);
}

char	**get_path(char **env)
{
	char	**path;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i ++;
	if (!env[i])
		error ("cmd not found (no PATH)");
	path = ft_split(ft_strchr(env[i], '=') + 1, ':');
	if (!*path)
		error ("cmd not found (PATH empty)");
	return (path);
}

void	do_cmd(char	*fct, char **env)
{
	char	**path;
	char	**args;
	int		pid;
	int		i;

	pid = fork();
	if (pid == -1)
		error("unexpected forking malfunction");
	if (!pid)
	{
		fct = extract_args(fct, &args);
		execve(fct, args, env);
		path = get_path(env);
		i = 0;
		while (path[i])
			try_path(fct, path[i ++], args, env);
		error("comande not found");
	}
	else
		waitpid(pid, &i, 0);
}
