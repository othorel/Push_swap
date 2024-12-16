/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:44:18 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/16 14:38:43 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_stack_after(t_stack *stack)
{
	while (stack && stack->top != NULL)
		stack = stack->top;
	return (stack);
}

t_stack	*get_stack_before(t_stack *stack)
{
	while (stack && stack->top && stack->top->top != NULL)
		stack = stack->top;
	return (stack);
}

t_stack	*create_stack(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->size = -1;
	new->a = -1;
	new->b = -1;
	new->top = NULL;
	return (new);
}
void 	get_stack(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = get_stack_after(*stack);
	tmp->top = new;
}

int	stack_size(t_stack *stack)
{
	int		size;
	
	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		size++;
		stack = stack->top;
	}
	return (size);
}
