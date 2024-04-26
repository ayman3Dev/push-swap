#include "push_swap.h"

void ft_sa(t_list **list)
{
	t_list *tmp;

	tmp = (*list);
	(*list) = (*list)->next;

	tmp->next = (*list)->next;
	(*list)->next = tmp;

}

void ft_ra(t_list **list)
{
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
	
}

void ft_rra(t_list **list)
{
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

}

void ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

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
	printf("a = %d b = %d \n", a, b);
	if (a > b)
		ft_sa(stack_a);
	
}

int ft_get_max(t_list *stack_a)
{
    if (stack_a == NULL)
        return 0;


    int max = stack_a->data; 
    stack_a = stack_a->next;

    while (stack_a != NULL)
    {
        if (stack_a->data > max)
            max = stack_a->data;
        stack_a = stack_a->next;
    }
    return max;
}
void ft_sort_three(t_list **stack_a)
{
	int max = ft_get_max(*stack_a);
	printf("++++++%d+++++", max);
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

void ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_sort_two(stack_b);
	if ((*stack_b)->data > (*stack_b)->next->data)
		ft_sa(stack_b);
	ft_pa(stack_b, stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_ra(stack_b);
	ft_pa(stack_b, stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_ra(stack_b);
}



