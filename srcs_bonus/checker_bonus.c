/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:09:07 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/24 15:09:07 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static char	**parse_arguments(int argc, char **argv)
{
	char	**split_argv;

	if (argc == 2)
	{
		split_argv = split(argv[1], ' ');
		if (!split_argv)
			return (NULL);
		return (split_argv);
	}
	return (argv + 1);
}


int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_argv;

	a = NULL;
	b = NULL;
	split_argv = parse_arguments(argc, argv);
	if (!split_argv)
		return (1);
	if (argc == 2)
		init_stack_a(&a, split_argv);
	else
		init_stack_a(&a, argv + 1);
	if (!execute(&a, &b))
	{
		free_stack(&a);
		free_stack(&b);
		if (argc == 2)
			free_split(split_argv);
		return (1);
	}
	if (stack_sorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	if (argc == 2)
		free_split(split_argv);
	return (0);
}
