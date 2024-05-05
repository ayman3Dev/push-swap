/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmodify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:09:17 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/01 16:31:57 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	if (list == NULL || (*list) == NULL)
		return ;
	tmp = (*list);
	while ((*list) != NULL)
	{
		tmp = (*list);
		(*list) = (*list)->next;
		free(tmp);
	}
	*list = NULL;
}

t_list	*ft_addlist(int num)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->data = num;
	new_node->index = 1;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstaddback(t_list **list, t_list *new_node)
{
	t_list	*tmp;

	tmp = *list;
	if (!list || !new_node)
		return ;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	while ((*list)->next != NULL)
	{
		(*list) = (*list)->next;
	}
	(*list)->next = new_node;
	*list = tmp;
}

int	ft_lstsize(t_list *stack_a)
{
	int	size;

	size = 0;
	if (stack_a == NULL)
		return (0);
	while (stack_a != NULL)
	{
		stack_a = stack_a->next;
		size++;
	}
	return (size);
}
