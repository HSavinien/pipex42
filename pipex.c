/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:43:51 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/24 18:34:25 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	fd_in;
	int fd_out;
	int	pipe_fd[2];
	int	pid;
	int	status;

	read_args(ac, av, &fd_in, &fd_out);
	if (pipe(pipe_fd) < 0)
		error("could not create pipe");
	pid = fork();
	if (pid < 0)
		error("unexpected forking malfunction");
	printf("fork created\n");//debug
	if (!pid)
		do_first_cmd(av[2], fd_in, pipe_fd, env);
	else
	{
		waitpid(pid, &status, 0);
		printf("\033[33m");//debug
		do_second_cmd(av[3], fd_out, pipe_fd, env);
	}
}
