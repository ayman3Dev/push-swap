/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:06:49 by aaaraba           #+#    #+#             */
/*   Updated: 2024/04/29 18:22:34 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (size);
}

static void	ft_free_split(char **array, int i)
{
	while (i)
	{
		free(array[--i]);
	}
	free(array);
}

static char	*allocate_string(const char *s, int start, int end)
{
	char	*array;
	int		i;

	i = 0;
	array = (char *)malloc(sizeof(char) * (end - start + 1));
	if (array == NULL)
		return (NULL);
	while (start < end && s[start])
	{
		array[i] = s[start];
		start++;
		i++;
	}
	array[start] = 0;
	return (array);
}

static int	len_worlds(char const *s, char c)
{
	int	j;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		size;
	int		i;

	if (s == NULL)
		return (NULL);
	size = ft_countword(s, c);
	if (size == 0)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (array == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == c)
			s++;
		array[i] = allocate_string(s, 0, len_worlds(s, c));
		if (array[i] == NULL)
		{
			ft_free_split(array, i);
			return (0);
		}
		s = s + len_worlds(s, c);
	}
	array[i] = NULL;
	return (array);
}
