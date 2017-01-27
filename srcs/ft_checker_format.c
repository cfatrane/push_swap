/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:10:56 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/27 14:42:16 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_checker_format(t_checker *checker)
{
	int	i;
	int	j;

	i = 0;
	while (checker->argum[i])
	{
		j = 0;
		while (checker->argum[i][j])
		{
			if (!ft_isdigit(checker->argum[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
