#include "push_swap.h"

void ft_lstclear(t_list *list)
{
	t_list	*tmp;

	if (list == NULL)
		return ;
	tmp = list;
	while(list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	free(list);
}
t_list *ft_addlist(int num)
{
	t_list *new_node;

	new_node =  (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->data = num;
	new_node->index = 1;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstaddback(t_list **list, t_list *new_node)
{
	t_list	*tmp;

	tmp = *list;
	if (!list || !new_node)
		return ;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	while ((*list)->next != NULL)
	{
		(*list) = (*list)->next;
	}
	(*list)->next = new_node;
	*list = tmp;
}

void ft_push_all_to_b(t_list **stack_a, t_list **stack_b)
{
	int size = ft_lstsize(*stack_a);
	int x = 0;
	if (size > 100)
		x = 36;
	else if (size <= 100)
		x = 16;
	int i = 0;
	while(i < size)
	{
		if ((*stack_a)->index <= i)
		{
			ft_pa(stack_a, stack_b);
			write(1, "pb\n", 3);
			i++;
		}
			
		else if ((*stack_a)->index <= i + x)
		{
			ft_pa(stack_a, stack_b);
			write(1, "pb\n", 3);
			if (ft_lstsize(*stack_b) > 1)
			{
				ft_ra(stack_b);
				write(1, "rb\n", 3);
			}
			i++;
		}
		else
		{
			ft_ra(stack_a);
			write(1, "ra\n", 3);
		}
	}
}

int ft_is_digit(char *str)
{
	int	i = 0;
	long long num = 0;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
				return (0);
		i++;	
	}
	num = ft_atoi(str);
	if (num < -2147483648 || num > 2147483647)
        return (0);
	return (num);
}
t_list *ft_check(char **argv)
{
	int j = 1;
	int x = 0;
	// int p = 0;
	long long num = 0;
	char **buffer = NULL;
	t_list *list;
	t_list *node;
	t_list *tmp;

	list = NULL;
	node = NULL;
	while (argv[j] != NULL)
	{
		buffer = ft_split(argv[j], ' ');
		if (buffer == NULL)
			return (NULL);
		x = 0;
		while (buffer[x] != NULL)
		{
			// p = 0;
			// while (buffer[x][p] != '\0')
			// {
			// 	if ((buffer[x][p] == '-' || buffer[x][p] == '+') && p == 0)
			// 		p++;
			// 	if (buffer[x][p] < '0' || buffer[x][p] > '9')
			// 			return (NULL);
			// 	p++;
			// }
			num = ft_is_digit(buffer[x]);
			// num = ft_atoi(buffer[x]);
			if (num < -2147483648 || num > 2147483647 || num == 0)
                return (NULL);
			tmp = list;
			while(list != NULL)
			{
				if (num == list->data)
					return (NULL);
				list = list->next;
			}
			list = tmp;
			node = ft_addlist(num);
			ft_lstaddback(&list, node);
			x++;
		}
		j++;
	}
	return (list);
}

void ft_push_to_a(t_list **stack_b, t_list **list)
{
	t_list *tmp = NULL;
	int size = ft_lstsize(*stack_b);
	int i = 0;
	int max = 0;
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
		if (max < (size / 2))
		{
			while (max > 0)
			{
				ft_ra(stack_b);
				write(1, "rb\n", 3);
				max--;
			}
		}
		else if (max >= (size / 2))
		{
			while (max < size)
			{
				ft_rra(stack_b);
				write(1, "rrb\n", 4);
				max++;
			}
		}
		ft_pa(stack_b, list);
		write(1, "pa\n", 3);
		size--;
	}
}

int main (int argc, char **argv)
{
	t_list *list;
	t_list *tmp = NULL;
	t_list *stack_b = NULL;

	if (argc <= 1)
		return (0);
	list = ft_check(argv);
	if (list == NULL)
		return (write(2, "Error\n", 6), 1);
	if (list->next == NULL)
		return (0);
	tmp = list;
	while (list != NULL && list->next != NULL && list->data < list->next->data)
	{
		list = list->next;
		if (list->next == NULL)
			return (0);
	}
	list = tmp;
	ft_get_index(tmp);
	ft_push_all_to_b(&list, &stack_b);
	ft_push_to_a(&stack_b, &list);
}
 