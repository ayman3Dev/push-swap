/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:36:32 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/06 17:54:32 by aaaraba          ###   ########.fr       */
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
		printf(" | %d |\n", list->data);
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
