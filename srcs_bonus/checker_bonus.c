/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:00:04 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/24 19:00:04 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	execute_instructions(char *c, t_stack_node **stack_a,
									t_stack_node **stack_b)
{
	if (ft_strcmp(c, "sa\n") == 0)
		sa(stack_a, true);
	else if (ft_strcmp(c, "sb\n") == 0)
		sb(stack_b, true);
	else if (ft_strcmp(c, "ss\n") == 0)
		ss(stack_a, stack_b, true);
	else if (ft_strcmp(c, "pa\n") == 0)
		pa(stack_a, stack_b, true);
	else if (ft_strcmp(c, "pb\n") == 0)
		pb(stack_b, stack_a, true);
	else if (ft_strcmp(c, "ra\n") == 0)
		ra(stack_a, true);
	else if (ft_strcmp(c, "rb\n") == 0)
		rb(stack_b, true);
	else if (ft_strcmp(c, "rr\n") == 0)
		rr(stack_a, stack_b, true);
	else if (ft_strcmp(c, "rra\n") == 0)
		rra(stack_a, true);
	else if (ft_strcmp(c, "rrb\n") == 0)
		rrb(stack_b, true);
	else if (ft_strcmp(c, "rrr\n") == 0)
		rrr(stack_a, stack_b, true);
	else
		return (0);
	return (1);
}

int	read_and_execute_instructions(t_stack_node **stack_a,
									t_stack_node **stack_b)
{
	char	*line;

	line = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!execute_instructions(line, stack_a, stack_b))
		{
			ft_printf("Error\n");
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

static int	process_arguments(int argc, char **argv, t_stack_node **stack_a)
{
	char	**split_args;

	if (argc == 2)
	{
		split_args = split(argv[1], ' ');
		if (!split_args || !*split_args)
		{
			ft_printf("Error\n");
			return (0);
		}
		init_stack_a(stack_a, split_args, argc);
		free_split(split_args);
	}
	else
		init_stack_a(stack_a, &argv[1], argc);
	return (1);
}

static int	check_and_execute(t_stack_node *stack_a, t_stack_node *stack_b)
{
	if (!read_and_execute_instructions(&stack_a, &stack_b))
		return (0);
	if (stack_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!process_arguments(argc, argv, &stack_a))
		return (0);
	check_and_execute(stack_a, stack_b);
	return (0);
}
