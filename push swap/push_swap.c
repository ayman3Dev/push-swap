/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:18:25 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/12 18:13:23 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_all_to_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	x;
	int	i;

	size = ft_lstsize(*stack_a);
	x = 16;
	if (size > 100)
		x = 36;
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->index <= i)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + x)
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
	}
}

int	ft_add_to_list(char **buffer, long long num, t_list **list)
{
	t_list	*tmp;
	t_list	*node;
	int		x;

	x = 0;
	tmp = NULL;
	while (buffer[x] != NULL)
	{
		if (ft_is_digit(buffer[x]) == 0)
			return (free_split(buffer), 0);
		num = ft_atoi(buffer[x]);
		if (num < -2147483648 || num > 2147483647)
			return (free_split(buffer), 0);
		tmp = *list;
		if ((is_duplicate(tmp, num)) == 0)
			return (free_split(buffer), 0);
		node = ft_addlist(num);
		if (node == NULL)
			return (free_split(buffer), 0);
		ft_lstaddback(list, node);
		x++;
	}
	return (1);
}

void	rotate(int max, int size, t_list **stack_b)
{
	if (max < (size / 2))
	{
		while (max-- > 0)
			ft_rb(stack_b);
	}
	else if (max >= (size / 2))
	{
		while (max++ < size)
			ft_rrb(stack_b);
	}
}

void	ft_push_to_a(t_list **stack_b, t_list **list)
{
	t_list	*tmp;
	int		size;
	int		i;
	int		max;

	size = ft_lstsize(*stack_b);
	while (size > 0)
	{
		i = 0;
		tmp = (*stack_b);
		while (tmp != NULL)
		{
			tmp->position = i;
			tmp = tmp->next;
			i++;
		}
		max = ft_get_max_position(*stack_b);
		rotate(max, size, stack_b);
		ft_pa(stack_b, list);
		size--;
	}
}

void f()
{
	system("leaks push_swap");
}
int	main(int argc, char **argv)
{
	t_list	*list;
	t_list	*tmp;
	t_list	*stack_b;

	atexit(f);
	tmp = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	list = ft_check(argv);
	if (list == NULL)
		return (ft_lstclear(&list), write(2, "Error\n", 6), 1);
	tmp = list;
	while (list != NULL && list->next != NULL && list->data < list->next->data)
		list = list->next;
	if (list->next == NULL)
		return (ft_lstclear(&tmp), 0);
	list = tmp;
	ft_check_size(&list, &stack_b);
	ft_get_index(tmp);
	ft_push_all_to_b(&list, &stack_b);
	ft_push_to_a(&stack_b, &list);
	ft_lstclear(&list);
}
