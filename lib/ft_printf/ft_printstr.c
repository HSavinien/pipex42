/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:43:51 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/03 19:40:08 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	ft_printstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, pf_strlen(str)));
}
