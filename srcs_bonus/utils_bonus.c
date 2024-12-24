/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:15:26 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/24 15:15:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	is_valid_instruction(char *line)
{
	return (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0
		|| ft_strcmp(line, "ss") == 0 || ft_strcmp(line, "pa") == 0
		|| ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "ra") == 0
		|| ft_strcmp(line, "rb") == 0 || ft_strcmp(line, "rr") == 0
		|| ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0
		|| ft_strcmp(line, "rrr") == 0);
}

int	execute_instruction(t_stack_node **a, t_stack_node **b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(a, false);
	else if (ft_strcmp(line, "sb") == 0)
		sb(b, false);
	else if (ft_strcmp(line, "ss") == 0)
		ss(a, b, false);
	else if (ft_strcmp(line, "pa") == 0)
		pa(a, b, false);
	else if (ft_strcmp(line, "pb") == 0)
		pb(b, a, false);
	else if (ft_strcmp(line, "ra") == 0)
		ra(a, false);
	else if (ft_strcmp(line, "rb") == 0)
		rb(b, false);
	else if (ft_strcmp(line, "rr") == 0)
		rr(a, b, false);
	else if (ft_strcmp(line, "rra") == 0)
		rra(a, false);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(b, false);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(a, b, false);
	else
		return (0);
	return (1);
}

int	execute(t_stack_node **a, t_stack_node **b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!is_valid_instruction(line))
		{
			ft_printf("Error\n");
			free(line);
			return (0);
		}
		if (!execute_instruction(a, b, line))
		{
			ft_printf("Error\n");
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	return (1);
}
