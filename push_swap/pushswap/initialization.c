/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Alls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiochau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/17/05 12:06:56 by apiochau          #+#    #+#             */
/*   Updated: 2024/17/05 14:06:59 by apiochau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_list *stack_a, int stack_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

static void	crea_list(t_list **stack_a, char **args, int i, int y)
{
	if (y == 1)
		*stack_a = ft_lstnew(ft_atoi(args[i]));
	else
		stack_add_bottom(&*stack_a, ft_lstnew(ft_atoi(args[i])));
}

t_list	*fill_stack_values(int ac, char **av)
{
	int		i;
	int		y;
	char	**args;
	t_list	*stack_a;

	i = -1;
	y = 1;
	stack_a = NULL;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 0;
		args = av;
	}
	while (args[++i])
	{
		crea_list(&stack_a, args, i, y);
		y++;
	}
	if (ac == 2)
		ft_free(args);
	return (stack_a);
}
