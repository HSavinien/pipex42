/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:38:46 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/21 16:34:08 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_args(int ac, char **av, int *fd_in, int *fd_out)
{
	if (ac != 5)
		exit(ft_printf("usage : %s <infile> <cmd1> <cmd2> <outfile>\n", av[0]));
	*fd_in = open(av[1], O_RDONLY);
	*fd_out = open(av[4], O_RDWR|O_CREAT, 0644);
	if (*fd_in < 0)
		exit(ft_printf("error : cannot read file %s\n", av[1]));
	if (*fd_out < 0)
		exit(ft_printf("error : cannot write in file %s\n", av[4]));
}
