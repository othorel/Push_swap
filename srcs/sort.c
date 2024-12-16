/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:45:34 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/16 14:40:27 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index(t_stack *stack)
{
	int	index;
	
	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->top;
	}
	return (index);
}

void	sort(t_stack **stack)
{
	int		index;
	
	if (is_sorted(*stack))
		return ;
	index = find_index(*stack);
	if ((*stack)->index == index)
		ra(*stack);
	if ((*stack)->top->index == index)
		rra(*stack);
	if ((*stack)->index > (*stack)->top->index)
		sa(*stack);
}
