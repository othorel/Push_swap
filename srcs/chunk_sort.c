/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:17:32 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/16 16:58:52 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_save(t_stack **a, t_stack **b)
{
	int		chunk_size;
	int		push;
	int		i;
	
	chunk_size = stack_size(*a);
	push = 0;
	i = 0;
	while (chunk_size > 6 && i < chunk_size && push < chunk_size / 2)
	{
		if ((*a)->size <= chunk_size / 2)
		{
			pb(a, b);
			push++;
		}
		else
			ra(a);
		i++;
	}
	while (chunk_size - push > 3)
	{
		pb(a, b);
		push++;
	}
}

static void	shift_stack(t_stack **a)
{
	int		i;
	int		size;
	
	size = stack_size(*a);
	i = get_index_position(a);
	if (i > size / 2)
	{
		while (i < size)
		{
			rra(a);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(a);
			i--;
		}
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	push_save(a, b);
	sort(a);
	while (*b)
	{
		position(a, b);
		move(a, b);
		do_move(a, b, 0, 0);
		
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
