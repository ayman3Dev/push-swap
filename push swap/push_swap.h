/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:29:49 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/12 18:22:39 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				position;
	struct s_list	*next;
}	t_list;

int		ft_add_to_list(char **buffer, long long num, t_list **list);
t_list	*ft_check(char **argv);
int		is_duplicate(t_list *list, int num);
int		ft_is_digit(char *str);
void	ft_sa(t_list **list);
void	ft_ra(t_list **list);
void	ft_rb(t_list **list);
void	ft_rra(t_list **list);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_sort_three(t_list **stack_a);
void	ft_sort_two(t_list **stack_a);
int		ft_get_max(t_list *stack_a);
void	ft_sort_five(t_list **stack_a, t_list **stack_b, int min);
void	ft_get_index(t_list *stack_a);
int		ft_lstsize(t_list *stack_a);
int		ft_get_max_position(t_list *stack_a);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
void	ft_rrb(t_list **stack_b);
t_list	*ft_addlist(int num);
void	ft_lstaddback(t_list **list, t_list *new_node);
void	ft_lstclear(t_list **list);
void	free_split(char **buffer);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);
int		ft_get_min_position(t_list *stack_a);
int		ft_strlen(char *s);
int		ft_check_size(t_list **list, t_list **stack_b);

#endif 
