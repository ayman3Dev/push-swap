/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:29:49 by aaaraba           #+#    #+#             */
/*   Updated: 2024/05/05 21:19:59 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
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
t_list	*ft_addlist(int num);
t_list	*ft_check(char **argv);
int		is_duplicate(t_list *list, int num);
int		ft_is_digit(char *str);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_sa(t_list **list);
void	ft_ra(t_list **list);
void	ft_rb(t_list **list);
void	ft_rra(t_list **list);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_sort_three(t_list **stack_a);
void	ft_sort_two(t_list **stack_a);
int		ft_get_max(t_list *stack_a);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);
void	ft_get_index(t_list *stack_a);
int		ft_lstsize(t_list *stack_a);
int		ft_get_max_position(t_list *stack_a);
void	display_list(t_list *list, char c);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
int		ft_is_sorted(t_list *stack_a);
void	ft_rrb(t_list **stack_b);
t_list	*ft_addlist(int num);
void	ft_lstaddback(t_list **list, t_list *new_node);
void	ft_lstclear(t_list **list);
void	free_split(char **buffer);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);

#endif 
