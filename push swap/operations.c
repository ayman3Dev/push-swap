/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:32:26 by aaaraba           #+#    #+#             */
/*   Updated: 2024/04/30 15:32:27 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **list)
{
	t_list	*tmp;

	tmp = (*list);
	(*list) = (*list)->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
}

void	ft_ra(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*list) == NULL || (*list)->next == NULL)
		return ;
	tmp = (*list);
	tmp2 = (*list)->next;
	while ((*list)->next != NULL)
	{
		(*list) = (*list)->next;
	}
	(*list)->next = tmp;
	(*list)->next->next = NULL;
	(*list) = tmp2;
}

void	ft_rra(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*list) == NULL || (*list)->next == NULL)
		return ;
	tmp = (*list);
	while ((*list)->next->next != NULL)
	{
		(*list) = (*list)->next;
	}
	tmp2 = (*list)->next;
	(*list)->next->next = tmp;
	(*list)->next = NULL;
	(*list) = tmp2;
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a)->next;
	if ((*stack_b) == NULL)
	{
		(*stack_b) = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		(*stack_b)->next = NULL;
	}
	else
	{
		(*stack_a)->next = (*stack_b);
		(*stack_b) = (*stack_a);
		(*stack_a) = tmp;
	}
}
void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sa(stack_b);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_ra(stack_b);
}

void	ft_sort_two(t_list **stack_a)
{
	int	a;
	int	b;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	if (a > b)
		ft_sa(stack_a);
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

void	ft_get_index(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*max;
	int		size;

	size = ft_lstsize(stack_a);
	tmp = stack_a;
	while (size > 1)
	{
		stack_a = tmp;
		max = NULL;
		while (stack_a != NULL)
		{
			if (max == NULL && stack_a->index == 1)
				max = stack_a;
			if (stack_a->index == 1 && max->data < stack_a->data)
				max = stack_a;
			stack_a = stack_a->next;
		}
		max->index = size;
		size--;
	}
}

int	ft_is_sorted(t_list *stack_a)
{
	if (stack_a == NULL || stack_a->next == NULL)
		return (0);
	while (stack_a != NULL)
	{
		if (stack_a->data < stack_a->next->data)
			stack_a = stack_a->next;
		else
			return (1);
	}
	return (0);
}
