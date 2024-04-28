#include "push_swap.h"


static void display_list(t_list *list)
{
	while(list != NULL)
	{
		printf("%d", list->data);
		printf(" [i:%d]->", list->index);
		list = list->next;
	}
}
void ft_sa(t_list **list)
{
	t_list *tmp;

	tmp = (*list);
	(*list) = (*list)->next;

	tmp->next = (*list)->next;
	(*list)->next = tmp;
	write(1, "sa\n", 3);
}

void ft_ra(t_list **list)
{
	if ((*list) == NULL || (*list)->next == NULL)
		return ;
	t_list *tmp;
	t_list *tmp2;
	tmp = (*list);
	tmp2 = (*list)->next;

	while ((*list)->next != NULL)
	{
		(*list) = (*list)->next;
	}
	(*list)->next = tmp;
	(*list)->next->next = NULL;
	(*list) = tmp2;
	write(1, "ra\n", 3);
	
}

void ft_rra(t_list **list)
{
	if ((*list) == NULL || (*list)->next == NULL)
		return ;
	t_list *tmp;
	t_list *tmp2;
	tmp = (*list);

	while ((*list)->next->next != NULL)
	{
		(*list) = (*list)->next;
	}
	tmp2 = (*list)->next;
	(*list)->next->next = tmp;
	(*list)->next = NULL;
	(*list) = tmp2;
	write(1, "rra\n", 4);

}

void ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	// if ((*stack_a) || (*stack_a)->next)
	// 	return ;
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
	write(1, "pa\n", 3);
}
void ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sa(stack_b);
}

void ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_ra(stack_b);
}

void ft_sort_two(t_list **stack_a)
{
	int a = (*stack_a)->data;
	int b = (*stack_a)->next->data;
	if (a > b)
		ft_sa(stack_a);
	
}

int ft_get_min(t_list *stack_a)
{
	return (0);
}

int ft_get_max_position(t_list *stack_a)
{
    if (stack_a == NULL)
        return 0;
	// int position;
    int max = stack_a->data;
	int max_pos = 0;
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
    return max_pos;
}
int ft_get_max(t_list *stack_a)
{
    if (stack_a == NULL)
        return 0;
	// int position;
    int max = stack_a->data; 
    stack_a = stack_a->next;

    while (stack_a != NULL)
    {
        if (stack_a->data > max)
		//position = stack_a->position;
            max = stack_a->data;
        stack_a = stack_a->next;
    }
    return max;
}
void ft_sort_three(t_list **stack_a)
{
	int max = ft_get_max(*stack_a);
	int a = (*stack_a)->data;
	int b = (*stack_a)->next->data;
	int c = (*stack_a)->next->next->data;

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

void ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	ft_pa(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_b, stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_ra(stack_a);
}
void ft_sort_five(t_list **stack_a, t_list **stack_b)
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

int ft_lstsize(t_list *stack_a)
{
	int size = 0;
	if (stack_a == NULL)
		return (0);
	while (stack_a != NULL)
	{
		stack_a = stack_a->next;
		size++;
	}
	return (size);
}

void ft_get_index(t_list *stack_a)
{
	t_list *tmp;
	t_list *max;
	int size = ft_lstsize(stack_a);

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
