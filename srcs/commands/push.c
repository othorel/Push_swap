/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:17:40 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/20 10:17:40 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
   t_stack_node	*push_node;

   if (!*src)
	  return ;
   push_node = *src;
   *src = (*src)->next;
   if (*src)
	  (*src)->prev = NULL;
   push_node->prev = NULL;
   if (!*dst)
   {
	  *dst = push_node;
	  push_node->next = NULL;
   }
   else
   {
	  push_node->next = *dst;
	  push_node->next->prev = push_node;
	  *dst = push_node;
   }
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool print)
{
   push(a, b);
   if (!print)
	  ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, bool print)
{
   push(b, a);
   if (!print)
	  ft_printf("pb\n");
}
