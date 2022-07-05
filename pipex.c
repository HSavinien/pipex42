/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:43:51 by tmongell          #+#    #+#             */
/*   Updated: 2022/07/04 18:49:59 by tmongell         ###   ########.fr       */
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
	do_first_cmd(av[2], fd_in, pipe_fd, env);
	dprintf(2, "first cmd done\033[33m\n");//debug
	do_second_cmd(av[3], fd_out, pipe_fd, env);
}
