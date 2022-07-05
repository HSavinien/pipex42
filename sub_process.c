/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:54:02 by tmongell          #+#    #+#             */
/*   Updated: 2022/07/05 14:23:04 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	do_first_cmd(char *cmd, int fd_in, int pipe_fd[2], char **env)
{
	int		pid;
	int		ret;
	char	*fct;
	char	**args;

	fct = get_true_fct(cmd, &args);
	ret = dup2(fd_in, 0);
	if (ret < 0)
		error("error on dup2 function (1)");
	ret = dup2(pipe_fd[1], 1);
	if (ret < 0)
		error("error on dup2 function (2)");
	pid = fork();
	if (!pid)
		do_cmd(fct, args, env);
	else
		waitpid(pid, &pid, 0);
	close(pipe_fd[1]);
	close(fd_in);
	exit(0);
}

void	do_second_cmd(char *cmd, int fd_out, int pipe_fd[2], char **env)
{
	int		pid;
	int		ret;
	char	*fct;
	char	**args;

	fct = get_true_fct(cmd, &args);
	ret = dup2(fd_out, 1);
	if (ret < 0)
		error("error on dup2 function (3)");
	ret = dup2(0, pipe_fd[0]);
	if (ret < 0)
		error("error on dup2 function (4)");
	pid = fork();
	if (pid = 0)
		do_cmd(fct, args, env);
	else
		waitpid(pid, &pid, 0);
	close(pipe_fd[0]);
	close(fd_out);
	exit(0);
}


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

void	do_cmd(char	*fct, char **args, char **env)
{
	char	**path;
	char	*cmd_path;
	int		i;

	path = get_path(env);
	dprintf(2, "args : %s\nargs+1 : %s\n", *args, args[1]);//debug
	i = 0;
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i ++], "/");
		cmd_path = ft_strjoin(cmd_path, fct);
		dprintf(2, "trying cmd %s\n", cmd_path);//debug
		execve(cmd_path, args, env);
		free(cmd_path);
	}
	error("function not found");
}
