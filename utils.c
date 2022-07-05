/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:25:34 by tmongell          #+#    #+#             */
/*   Updated: 2022/07/05 18:14:44 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg)
{
	write (2, "Error : \n", 9);
	write (2, msg, ft_strlen(msg));
	write (2, "\n", 1);
	exit(1);
}

char	*extract_args(char	*base, char ***args)
{
	int		i;
	char	*cmd;

	if (!base || !*base)
		error("trying to execute empty command");
	*args = ft_split_word(base);
	cmd = *args[0];
	i = 0;
	args ++;
	return (cmd);
}
