/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:44:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/07/06 14:48:56 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf/libftprintf.h"

# define STD_IN 0
# define STD_OUT 1

//parsing----------------------------------------------------------------parsing

void	read_args(int ac, char **av, int *fd_in, int *fd_out);

//sub_process--------------------------------------------------------sub_process

char	**get_path(char **env);
void	do_cmd(char	*fct, char **env);

//utils--------------------------------------------------------------------utils

void	error(char *msg);
char	*extract_args(char *base, char ***args);

#endif
