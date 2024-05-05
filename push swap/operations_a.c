/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:32:26 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/05 16:12:09 by aaaraba          ###   ########.fr       */
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
	write (1, "sa\n", 3);
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
	write (1, "ra\n", 3);
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
	write (1, "rra\n", 4);
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
	write (1, "pa\n", 3);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_sort_three(stack_a);
	if ((*stack_b)->data > (*stack_b)->next->data)
		ft_sa(stack_b);
	ft_pa(stack_b, stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_ra(stack_a);
	ft_pa(stack_b, stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_ra(stack_a);
}
