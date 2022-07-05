/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:54:02 by tmongell          #+#    #+#             */
/*   Updated: 2022/07/05 17:47:38 by tmongell         ###   ########.fr       */
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
	dprintf(2, "found path : %s\n", env[i]);//debug
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
	dprintf(2, "entering fct do_cmd\n");//debug
	if (!pid)
	{
		dprintf(2, "entering child process\n");//debug
		fct = extract_args(fct, &args);
		path = get_path(env);
		dprintf(2, "funct, args, and path env var extracted\n");//debug
		i = 0;
		execve(fct, args, env);
		while (path[i])
		{
			dprintf(2, "\e[1mloop\e[0m\n");//debug
			cmd_path = ft_strjoin(path[i ++], "/");
			cmd_path = ft_strjoin(cmd_path, fct);
			dprintf(2, "trying cmd %s\n", cmd_path);//debug
			execve(cmd_path, args, env);
			free(cmd_path);
		}
		error("comande not found");
	}
	else
	{
		waitpid(pid, &i, 0);
		dprintf(2, "back to parent process\n");
	}
}
