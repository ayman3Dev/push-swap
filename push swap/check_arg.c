/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:15:05 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/05 16:15:22 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_list *list, int num)
{
	while (list != NULL)
	{
		if (num == list->data)
			return (0);
		list = list->next;
	}
	return (1);
}

t_list	*ft_check(char **argv)
{
	int		j;
	char	**buffer;
	t_list	*list;
	t_list	*node;
	t_list	*tmp;

	j = 1;
	buffer = NULL;
	tmp = NULL;
	list = NULL;
	node = NULL;
	while (argv[j] != NULL)
	{
		buffer = ft_split(argv[j], ' ');
		if (buffer == NULL)
			return (ft_lstclear(&tmp), NULL);
		if ((ft_add_to_list(buffer, 0, &list)) == 0)
			return (ft_lstclear(&tmp), NULL);
		free_split(buffer);
		j++;
	}
	return (list);
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		return ;
	while (buffer && buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
