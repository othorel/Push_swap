/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:50:31 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/20 12:50:31 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	char		*next_word;
	int			len;
	int			i;

	while (s[*cursor] == c && s[*cursor] != '\0')
		++(*cursor);
	if (s[*cursor] == '\0')
		return (NULL);
	len = 0;
	while (s[*cursor + len] != c && s[*cursor + len] != '\0')
		++len;
	next_word = malloc((size_t)(len + 1) * sizeof(char));
	if (!next_word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		next_word[i] = s[*cursor];
		++i;
		++(*cursor);
	}
	next_word[i] = '\0';
	return (next_word);
}

static void	free_result_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;
	int		cursor;

	words_count = count_words(s, c);
	if (words_count == 0)
		return (NULL);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 1));
	if (!result_array)
		return (NULL);
	cursor = 0;
	i = 0;
	while (i < words_count)
	{
		result_array[i] = get_next_word(s, c, &cursor);
		if (!result_array[i])
		{
			free_result_array(result_array);
			return (NULL);
		}
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}
