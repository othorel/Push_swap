/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:30:02 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/16 17:00:57 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>


typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				size;
	int	  			  a;
	int	 			  b;
	struct s_stack	*top;
}				t_stack;

int	is_int(const char **av);

void	sort_stack(t_stack **a, t_stack **b);

void	do_move(t_stack **a, t_stack **b, int ra, int rb);

int	is_sorted(t_stack *stack);
t_stack	*value(int ac, char **av);
void	assign(t_stack *stack, int size);

void	get_move(t_stack **a, t_stack **b);
void	move(t_stack **a, t_stack **b);

int	get_index_position(t_stack **stack);
void	position(t_stack **a, t_stack **b);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **a, t_stack **b);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **a, t_stack **b);

void	sort(t_stack **stack);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **a, t_stack **b);

t_stack	*get_stack_after(t_stack *stack);
t_stack	*get_stack_before(t_stack *stack);
t_stack	*create_stack(int value);
void 	get_stack(t_stack **stack, t_stack *new);
int	stack_size(t_stack *stack);

int	nbstr_cmp(const char *s1, const char *s2);

int	ft_atol(const char *str);
void	exit_error(t_stack **a, t_stack **b);
int	nb_abs(int nb);
void	free_stack(t_stack **stack);


#endif