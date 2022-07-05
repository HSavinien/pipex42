/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:44:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/07/04 16:44:30 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include "library/libft/libft.h"
#include "library/ft_printf/libftprintf.h"

//parsing----------------------------------------------------------------parsing

void	read_args(int ac, char **av, int *fd_in, int *fd_out);

//sub_process--------------------------------------------------------sub_process

void	do_first_cmd(char *cmd, int fd_in,int pipe_fd[2], char **env);
void	do_second_cmd(char *cmd, int fd_in, int pipe_fd[2], char **env);
void	do_cmd(char	*fct, char **args, char **env);

//utils--------------------------------------------------------------------utils

void	error(char *msg);
char	*get_true_fct(char	*base, char ***args);

#endif

#include <stdio.h>
