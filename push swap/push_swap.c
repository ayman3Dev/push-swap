#include "push_swap.h"


t_list *ft_addlist(int num)
{
	t_list *new_node;

	new_node =  (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->data = num;
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
	long long num = 0;
	t_list *list;
	t_list *node;
	t_list *tmp;

	list = NULL;
	node = NULL;
	list = ft_check(argv);
	tmp = list;
	while (list != NULL && list->next != NULL && list->data < list->next->data)
	{
		list = list->next;
		if (list->next == NULL)
			return (write(1, "error\n", 6), 1);
	}
	list = tmp;
	t_list *stack_b;
	ft_sort_five(&list, &stack_b);
	puts("stack_a");
	while(list != NULL)
	{
		printf(" %d ", list->data);
		list = list->next;
	}
	puts("\nstack_b");
	while(stack_b != NULL)
	{
		printf(" %d ", stack_b->data);
		stack_b = stack_b->next;
	}
}



