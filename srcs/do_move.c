/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:32:20 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/16 17:04:54 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void do_rev_rotate(t_stack **a, t_stack **b, int *costa, int *costb)
{
	while (*costa < 0 && *costb < 0)
	{
		rrr(a, b);
		(*costa)++;
		(*costb)++;
	}
}

static void do_rotate(t_stack **a, t_stack **b, int *costa, int *costb)
{
	while (*costa > 0 && *costb > 0)
	{
		rr(a, b);
		(*costa)--;
		(*costb)--;
	}
}


static void do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else
		{
			rra(a);
			(*cost)++;
		}
	}
}

static void do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else
		{
			rrb(b);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int ra, int rb)
{
	if (ra < 0 && rb < 0)
		do_rev_rotate(a, b, &ra, &rb);
	else if (ra > 0 && rb > 0)
		do_rotate(a, b, &ra, &rb);
	do_rotate_a(a, &ra);
	do_rotate_b(b, &rb);
	pa(a, b);
}
