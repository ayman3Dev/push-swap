/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:26:51 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/05 21:36:18 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_list **stack_a, t_list **stack_b)
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
	write (1, "pb\n", 3);
}

void	ft_rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	tmp2 = (*stack_b)->next;
	while ((*stack_b)->next != NULL)
	{
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b)->next = tmp;
	(*stack_b)->next->next = NULL;
	(*stack_b) = tmp2;
	write (1, "rb\n", 3);
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	while ((*stack_b)->next->next != NULL)
	{
		(*stack_b) = (*stack_b)->next;
	}
	tmp2 = (*stack_b)->next;
	(*stack_b)->next->next = tmp;
	(*stack_b)->next = NULL;
	(*stack_b) = tmp2;
	write (1, "rrb\n", 4);
}

void	ft_sort_three(t_list **stack_a)
{
	int	max;
	int	a;
	int	b;

	max = ft_get_max(*stack_a);
	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	if (max == a)
	{
		ft_ra(stack_a);
		ft_sort_two(stack_a);
	}
	else if (max == b)
	{
		ft_rra(stack_a);
		ft_sort_two(stack_a);
	}
	else
		ft_sort_two(stack_a);
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		min;
	int		i;
	int		size;

	i = 0;
	min = 0;
	tmp = (*stack_a);
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->data < min)
		{
			min = (*stack_a)->data;
		}
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = tmp;
	while ((*stack_a)->data != min)
        ft_ra(stack_a);
	ft_pb(stack_a, stack_b);
	size = ft_lstsize(*stack_a);
	if (size == 3)
		ft_sort_three(stack_a);
	ft_pa(stack_b, stack_a);
}
