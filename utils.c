/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:25:34 by tmongell          #+#    #+#             */
/*   Updated: 2022/07/04 18:46:40 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg)
{
	dprintf(2, "debug error : %s\n", msg);//debug
	ft_printf("Error :\n%s\n", msg);
	exit(1);
}

char	*get_true_fct(char	*base, char ***args)
{
	int		i;
	char	*cmd;

	if (!base || !*base)
		error("trying to execute empty command");
	*args = ft_split_word(base);
	cmd = *args[0];
	i = 0;
	while ((*args)[i])
	{
		(*args)[i] = (*args)[i + 1];
		i ++;
	}
	if (!(*args)[0])
		args = NULL;
	return (cmd);
}
