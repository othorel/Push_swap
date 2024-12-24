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

int	is_valid_instruction(char *line);
int	execute_instruction(t_stack_node **a, t_stack_node **b, char *line);
int	execute(t_stack_node **a, t_stack_node **b);

#endif