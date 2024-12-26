/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:11:13 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/24 15:11:13 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include <stdbool.h> 
# include <limits.h> 
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

int		execute_instructions(char *c, t_stack_node **stack_a,
			t_stack_node **stack_b);
int		read_and_execute_instructions(t_stack_node **stack_a,
			t_stack_node **stack_b);
int		validate_arguments(int ac, char **av);
int		ft_strcmp(const char *s1, const char *s2);
void	push(t_stack_node **dst, t_stack_node **src);
void	free_split(char **array);

#endif