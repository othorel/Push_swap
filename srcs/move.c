/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:19:32 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/16 17:09:29 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;
	int		j;
	
	tmp = *a;
	tmp2 = *b;
	i = get_index_position(tmp);
	j = get_index_position(tmp2);
	while (tmp2)
	{
		tmp2->a = tmp2->pos;
		if (tmp2->pos > j / 2)
			tmp2->b = (j - tmp2->pos) * -1;
		tmp2->a = tmp2->pos;
		if (tmp2->pos > i / 2)
			tmp2->a = (i - tmp2->pos) * -1;
		tmp2 = tmp2->top;
	}
}

void	move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;
	int		costa;
	int		costb;
	
	tmp = *b;
	i = 2147483647;
	while (tmp)
	{
		if (nb_abs(tmp->a) + nb_abs(tmp->b) < nb_abs(i))
		{
			i = nb_abs(tmp->a) + nb_abs(tmp->b);
			a = tmp->a;
			b = tmp->b;
		}
		tmp = tmp->top;
	}	
}