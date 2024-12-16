/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:55:22 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/16 14:56:36 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->top;
		i++;
	}
}

int	get_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		j;
	
	tmp = *stack;
	i = 2147483647;
	get(stack);
	j = tmp->pos;
	while (tmp)
	{
		if (tmp->size < i)
		{
			i = tmp->index;
			j = tmp->pos;
		}
		tmp = tmp->top;
	}
	return (j);
}

static int get_index(t_stack **a, int index, int size, int pos)
{
	t_stack	*tmp;
	
	tmp = *a;
	while (tmp)
	{
		if (tmp->index > index && tmp->index < size)
		{
			size = tmp->index;
			pos = tmp->pos;
		}
		tmp = tmp->top;
	}
	if (size != 2147483647)
		return (pos);
	while (tmp)
	{
		if (tmp->index < size)
		{
			size = tmp->index;
			pos = tmp->pos;
		}
		tmp = tmp->top;
	}
	return (pos);
}

void	position(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		index;
	
	tmp = *b;
	get(a);
	get(b);
	index = 0;
	while (tmp)
	{
		index = get_index(a, tmp->index, 2147483647, index);
		tmp->size = index;
		tmp = tmp->top;
	}
}
