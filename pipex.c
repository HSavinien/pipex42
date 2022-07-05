/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:43:51 by tmongell          #+#    #+#             */
/*   Updated: 2022/07/05 18:29:54 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	fd_in;
	int fd_out;
	int	pipe_fd[2];

	read_args(ac, av, &fd_in, &fd_out);
	if (pipe(pipe_fd) < 0)
		error("could not create pipe");
	//dup for first cmd : fd_in to std_in, std_out to pipe_in
	dup2(fd_in, STD_IN);
	dup2(pipe_fd[1], STD_OUT);
	//do first command
	do_cmd(av[2], env);
	//close unneeded fd : fd_in, pipe_in
	close(fd_in);
	close(pipe_fd[1]);
	dprintf(2, "\e[33mfirst command done!\e[0m\n");
	//dup for second cmd : pipe_out to std_in, std_out to fd_out
	dup2(pipe_fd[0], STD_IN);
	dup2(fd_out, STD_OUT);
	//do second cmd
	do_cmd(av[3], env);
	//close all remaining fd : pipe_out, fd_out
	close(pipe_fd[0]);
	close(fd_out);
}
