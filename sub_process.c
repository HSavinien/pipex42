/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:54:02 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/24 18:34:16 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_first_cmd(char *cmd, int fd_in,int pipe_fd[2], char **env)
{
	int		pid;
	char	*fct;
	char	**args;

//	printf("entering first cmd\n");//debug
	fct = get_true_fct(cmd, &args, env);
//	printf("cmd to execute is %s\n", fct);//debug
	dup2(0, fd_in);
	dup2(1, pipe_fd[1]);

	pid = fork();
	if (!pid)
		execve(fct, args, env);
	else
		waitpid(pid, &pid, 0);
	close(pipe_fd[1]);
	close(fd_in);
	exit(0);
}

void	do_second_cmd(char *cmd, int fd_out, int pipe_fd[2], char **env)
{
	int		pid;
	char	*fct;
	char	**args;

	fct = get_true_fct(cmd, &args, env);
	dup2(1, fd_out);
	dup2(pipe_fd[0], 0);
	pid = fork();
	if (!pid)
		execve(fct, args, env);
	else
		waitpid(pid, &pid, 0);
	close(pipe_fd[0]);
	close(fd_out);
	exit(0);
}
