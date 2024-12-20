/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:37:41 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/20 10:37:41 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *node)
{
	while (*b != node->target_node && *a != node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *node)
{
	while (*b != node->target_node && *a != node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;

	node = get_cheapest(*a);
	if (node->above_median && node->target_node->above_median)
		rotate_both(a, b, node);
	else if (!(node->above_median) && !(node->target_node->above_median))
		rev_rotate_both(a, b, node);
	prep_for_push(a, node, 'a');
	prep_for_push(b, node->target_node, 'b');
	pb(b, a, false);
}

static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_turk(t_stack_node **a, t_stack_node **b)
{
	int		len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
