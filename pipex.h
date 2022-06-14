/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:44:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/14 17:55:07 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "library/libft/libft.h"
#include "library/ft_printf/libftprintf.h"


void	read_args(int ac, char **av, int *fd_in, int *fd_out);

#endif
