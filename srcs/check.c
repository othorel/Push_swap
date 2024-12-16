/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:45:35 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/16 16:52:15 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int av_is_nb(const char *av)
{
	int	i;
	
	i = 0;
	if ((av[i] == '-' || av[i] == '+') && av[i + 1])
		i++;
	if (av[i] && ft_isdigit(av[i]))
		i++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	av_is_zero(const char *av)
{
	int	i;
	
	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i])
		return (0);
	return (1);
}

static int	av_dup(const char **av)
{
	int	i;
	int	j;
	
	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (i != j && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_int(const char **av)
{
	int	i;
	int	zero;
	
	i = 1;
	zero = 0;
	while (av[i])
	{
		if (!av_is_nb(av[i]))
			return (0);
		zero += av_is_zero(av[i]);
		i++;
	}
	if (zero > 1)
		return (0);
	if (av_dup(av))
		return (0);
	return (1);
}
