/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:34:17 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/12 22:40:52 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_lstclear(stack_a);
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
