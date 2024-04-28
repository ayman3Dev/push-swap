#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_list{
	int data;
	int index;
	int position;
	struct s_list *next;
}t_list;


long	ft_atoi(const char *str); 
char	**ft_split(char const *s, char c);
void ft_sa(t_list **list);
void ft_ra(t_list **list);
void ft_rra(t_list **list);
void ft_pa(t_list **stack_a, t_list **stack_b);
void ft_ss(t_list **stack_a, t_list **stack_b);
void ft_rr(t_list **stack_a, t_list **stack_b);
void ft_sort_three(t_list **stack_a);
void ft_sort_two(t_list **stack_a);
int ft_get_max(t_list *stack_a);
void ft_sort_five(t_list **stack_a, t_list **stack_b);
void ft_get_index(t_list *stack_a);
int ft_lstsize(t_list *stack_a);
int ft_get_max_position(t_list *stack_a);

#endif 
