#include "push_swap.h"

static void display_list(t_list *list, char c)
{
	while(list != NULL)
	{
		// printf("Data : %d || Index : %d | Pos : %d \n", list->data, list->index, list->position);
		printf("%d ", list->data);
		list = list->next;
	}
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
			ft_pa(stack_a, stack_b);
		else if ((*stack_a)->index <= i + x)
		{
			ft_pa(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1)
				ft_ra(stack_b);
			puts("here");
		}
		else
			ft_ra(stack_a);
		i++;
	}
}
t_list *ft_check(char **argv)
{
	int i = 0;
	int j = 1;
	int x = 0;
	int p = 0;
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
		x = 0;
		while (buffer[x] != NULL)
		{
			num = ft_atoi(buffer[x]);
			if (num < -2147483648 || num > 2147483647)
                return (write(1, "error\n", 6), NULL);
			tmp = list;
			while(list != NULL)
			{
				if (num == list->data)
					return (write(1, "error\n", 6), NULL);
				list = list->next;
			}
			list = tmp;
			node = ft_addlist(num);
			ft_lstaddback(&list, node);
			p = 0;
			while (buffer[x][p] != '\0')
			{
				if ((buffer[x][p] == '-' || buffer[x][p] == '+') && p == 0)
					p++;
				if (buffer[x][p] < '0' || buffer[x][p] > '9')
					return (write(1, "error\n", 6), NULL);
				p++;
			}
			x++;
		}
		j++;
	}
	return (list);
}

int main (int argc, char **argv)
{
	if (argc <= 2)
		return (0);
	t_list *list;
	t_list *tmp;

	list = ft_check(argv);
	tmp = list;
	while (list != NULL && list->next != NULL && list->data < list->next->data)
	{
		list = list->next;
		if (list->next == NULL)
			return (write(1, "error\n", 6), 1);
	}
	list = tmp;

	t_list *stack_b = NULL;
	ft_get_index(tmp);
	ft_push_all_to_b(&list, &stack_b);
	int i = 0;
	t_list *tmp_b = stack_b;
	while (stack_b != NULL)
	{
		stack_b->position = i;
		stack_b = stack_b->next;
		i++;
	}
	stack_b = tmp_b;

	int size = ft_lstsize(stack_b);

	int max;

	while (size > 0)
	{
		i = 0;
		tmp = stack_b;
		while (tmp != NULL)
		{
			tmp->position = i;
			tmp = tmp->next;
			i++;
		}
		max = ft_get_max_position(stack_b);
		if (max < (size / 2))
		{
			while (max > 0)
			{
				ft_ra(&stack_b);
				max--;
			}
		}
		else if (max >= (size / 2))
		{
			while (max < size)
			{
				ft_rra(&stack_b);
				max++;
			}
		}
		ft_pa(&stack_b, &list);	
		size--;
	}
	display_list(list, 'a');
	
}
