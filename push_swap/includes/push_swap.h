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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

t_list		*fill_stack_values(int ac, char **av);
void		assign_index(t_list *stack_a, int ac);
int			is_sorted(t_list *stack);
void		petit_tri(t_list **stack);
void		tri(t_list **stack_a, t_list **stack_b);
int			get_lowest_index_position(t_list **stack);
void		get_target_position(t_list **stack_a, t_list **stack_b);
void		get_cost(t_list **stack_a, t_list **stack_b);
void		cheapest_move(t_list **stack_a, t_list **stack_b);
void		move(t_list **a, t_list **b, int cost_a, int cost_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
t_list		*get_stack_bottom(t_list *stack);
t_list		*get_stack_before_bottom(t_list *stack);
t_list		*ft_lstnew(int value);
void		stack_add_bottom(t_list **stack, t_list *new);
int			ft_lstsize(t_list	*stack);
void		free_stack(t_list **stack);
void		ft_putstr(char *str);
int			nb_abs(int nb);
void		ft_error(char *msg);
void		ft_error_1(char *msg, char **args);
void		ft_free(char **str);
void		exit_error(t_list **stack_a, t_list **stack_b);
void		verif_args(int argc, char **argv);
void		verif_args_2(int y, int i, char **args, long tmp);

#endif
