/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:29:49 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/14 13:58:30 by aaaraba          ###   ########.fr       */
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

void	ft_sa(t_list **list);
void	ft_ra(t_list **list);
void	ft_rb(t_list **list);
void	ft_rra(t_list **list);
void	ft_rrb(t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
int		ft_lstsize(t_list *stack_a);
t_list	*ft_addlist(int num);
int		ft_add_to_list(char **buffer, long num, t_list **list);
void	ft_lstaddback(t_list **list, t_list *new_node);
void	ft_lstclear(t_list **list);
void	ft_sort_two(t_list **stack_a);
void	ft_sort_three(t_list **stack_a);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);
void	ft_sort_five(t_list **stack_a, t_list **stack_b, int min);
int		ft_get_max_position(t_list *stack_a);
int		ft_get_min_position(t_list *stack_a);
int		ft_get_max(t_list *stack_a);
void	ft_get_index(t_list *stack_a);
t_list	*ft_check(char **argv);
int		ft_check_size(t_list **list, t_list **stack_b);
int		ft_is_digit(char *str);
int		is_duplicate(t_list *list, int num);
char	**ft_split(char const *s, char c);
void	free_split(char **buffer);
long	ft_atoi(const char *str);
int		ft_strlen(char *s);

#endif 
