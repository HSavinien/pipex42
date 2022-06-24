/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:25:34 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/24 18:25:29 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg)
{
	ft_printf("Error :\n%s\n", msg);
	exit(1);
}

/*
char	*find_cmd(char *short_cmd)
{
}
*/

char	*get_true_fct(char	*base, char ***args, char **env)
{
	int		i;
	char	*cmd;

	if (!base || !*base)
		error("trying to execute empty command");
	*args = ft_split_word(base);
//	cmd = find_cmd(*args[0], env);
	cmd = *args[0];
	printf("%s\n", cmd);//debug
	i = 0;
	while ((*args)[i])
	{
		(*args)[i] = (*args)[i + 1];
		printf("%s\n", (*args)[i]);//debug
		i ++;
	}
	return (cmd);
	(void) env;
}
