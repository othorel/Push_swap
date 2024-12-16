/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sa_sb_ss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:21:47 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/16 14:30:13 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack *stack)
{
	int	tmp;
	
	if (stack == NULL || stack->top == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->top->value;
	stack->top->value = tmp;
	tmp = stack->index;
	stack->index = stack->top->index;
	stack->top->index = tmp;
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");	
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}
