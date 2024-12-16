/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:43:57 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/16 17:02:17 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->top)
	{
		if (stack->value > stack->top->value)
			return (0);
		stack = stack->top;
	}
	return (1);
}

static void push(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		sa(a);
	else if (size == 3)
		sort(a);
	else if (size > 3 && !is_sorted(*a))
		sort_stack(a, b);
}

t_stack	*value(int ac, char **av)
{
	t_stack	*stack;
	long	nb;
	int		i;
	
	stack = NULL;
	i = 1;
	nb = 0;
	while (i < ac)
	{
		nb = ft_atol(av[i]);
		if (nb < -2147483648 || nb > 2147483647)
			exit_error(&stack, NULL);
		if (i == 1)
			stack = create_stack(nb);
		else
			get_stack(&stack, create_stack(nb));
		i++;
	}
	return (stack);
}

void	assign(t_stack *stack, int size)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;
	
	while (--size > 0)
	{
		tmp = stack;
		i = -2147483648;
		tmp2 = NULL;
		while (tmp)
		{
			if (tmp->value == 2147483647 && tmp->index == 0)
				tmp->index = i;
			if (tmp->value > i && tmp->index == 0)
			{
				i = tmp->value;
				tmp2 = tmp;
				tmp = stack;
			}
			else
				tmp = tmp->top;
		}
		if (tmp2)
			tmp2->index = size;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	
	if (ac < 2)
		return (0);
	if (!is_int((const char **)av))
		exit_error(NULL, NULL);
	b = NULL;
	a = value(ac, av);
	size = stack_size(a);
	assign(a, size + 1);
	push(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
