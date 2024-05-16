/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:36:32 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/12 23:25:38 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_position(t_list *stack_a)
{
	int	max;
	int	max_pos;

	max = stack_a->data;
	max_pos = 0;
	if (stack_a == NULL)
		return (0);
	stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		if (stack_a->data > max)
		{
			max_pos = stack_a->position;
			max = stack_a->data;
		}
		stack_a = stack_a->next;
	}
	return (max_pos);
}

int	ft_get_min_position(t_list *stack_a)
{
	int	max;
	int	max_pos;

	max = stack_a->data;
	max_pos = 0;
	if (stack_a == NULL)
		return (0);
	stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		if (stack_a->data < max)
		{
			max_pos = stack_a->position;
			max = stack_a->data;
		}
		stack_a = stack_a->next;
	}
	return (max_pos);
}

int	ft_get_max(t_list *stack_a)
{
	int	max;

	max = stack_a->data;
	if (stack_a == NULL)
		return (0);
	stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		if (stack_a->data > max)
			max = stack_a->data;
		stack_a = stack_a->next;
	}
	return (max);
}
