/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:36:32 by aaaraba           #+#    #+#             */
/*   Updated: 2024/04/30 15:36:33 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	display_list(t_list *list, char c)
{
	printf("%c\n", c);
	while (list != NULL)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}

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
	ft_pa(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_b, stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_ra(stack_a);
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
