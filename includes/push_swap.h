/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:30:02 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/20 11:55:24 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool 				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

/* ************************************************************************** */
/*                                  HANDLE ERRORS                             */
/* ************************************************************************** */

int		error_syntax(char *str);
int		error_duplicate(t_stack_node *a, int nbr);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a);

/* ************************************************************************** */
/*                                  STACK INIT                                */
/* ************************************************************************** */

void	init_stack_a(t_stack_node **a, char **av);

/* ************************************************************************** */
/*									NODES INIT								  */
/* ************************************************************************** */

void 			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			prep_to_push(t_stack_node **stack, t_stack_node *top_node, char name);
t_stack_node	*get_cheapest(t_stack_node *stack);

/* ************************************************************************** */
/*                                  STACK UTILS                               */
/* ************************************************************************** */

int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

/* ************************************************************************** */
/*                                  OPERATIONS                                */
/* ************************************************************************** */

void	sa(t_stack **stack_a, bool print);
void	sb(t_stack **stack_b, bool print);
void	ss(t_stack **stack_a, t_stack **stack_b, bool print);
void	pa(t_stack **stack_a, t_stack **stack_b, bool print);
void	pb(t_stack **stack_a, t_stack **stack_b, bool print);
void	ra(t_stack **stack_a, bool print);
void	rb(t_stack **stack_b, bool print);
void	rr(t_stack **stack_a, t_stack **stack_b, bool print);
void	rra(t_stack **stack_a, bool print);
void	rrb(t_stack **stack_b, bool print);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool print);


#endif