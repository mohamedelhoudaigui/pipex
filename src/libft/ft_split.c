/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:54:26 by mel-houd          #+#    #+#             */
/*   Updated: 2023/11/10 19:53:36 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			res++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (res);
}

static int	word_size(char const *s, char c, int i)
{
	int	res;

	res = 0;
	while (s[i] && s[i] != c)
	{
		res++;
		i++;
	}
	return (res);
}

static void	memory_free(char **strings, int max_index)
{
	while (max_index >= 0)
		free(strings[max_index--]);
	free(strings);
}

static int	fill_string(char const *s, char c, char **res, int number_words)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while (j < number_words)
	{
		while (s[i] == c)
			i++;
		size = word_size(s, c, i);
		res[j] = ft_substr(s, i, size);
		if (res[j] == NULL)
		{
			memory_free(res, j);
			return (1);
		}
		j++;
		i += size;
	}
	res[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		number_words;
	char	**res;

	number_words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (number_words + 1));
	if (!res || fill_string(s, c, res, number_words))
		return (NULL);
	return (res);
}
