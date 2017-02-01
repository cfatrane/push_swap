/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:55:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/02/01 15:14:03 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack	*ft_create_elem_stack(size_t nbr)
{
	t_stack	*stack;

	if (!(stack = (t_stack*)malloc(sizeof(*stack))))
		return (NULL);
	stack->nbr = nbr;
	stack->next = NULL;
	return (stack);
}

t_stack	*ft_stack_push_params(int ac, char **av)
{
	int			i;
	t_stack		*stack;

	stack = NULL;
	i = 1;
	if (ac)
		while (i < ac)
		{
			if (ft_stack_format(av[i]) == -1 || ft_stack_max(ft_atoll(av[i])) == -1)
				return (NULL);
			ft_stack_push_back(&stack, ft_atoll(av[i]));
			i++;
		}
	if (ft_stack_doublon(stack) == -1)
		return (NULL);
	return (stack);
}

int		main(int argc, char **argv)
{
	t_checker	*checker;

	if (argc == 1)
		return (-1);
	if (!(checker = ft_memalloc(sizeof(t_checker))))
		return (-1);
	if ((checker->stack_a = ft_stack_push_params(argc, argv)) == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	ft_checker(checker);
	return (0);
}
