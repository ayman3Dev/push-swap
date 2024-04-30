/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:29:49 by aaaraba           #+#    #+#             */
/*   Updated: 2024/04/30 15:29:50 by aaaraba          ###   ########.fr       */
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

int		is_digit(const char *s);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_sa(t_list **list);
void	ft_ra(t_list **list);
void	ft_rra(t_list **list);
void	ft_pa(t_list **stack_a, t_list **stack_b);
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

#endif 
