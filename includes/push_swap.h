/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/05/20 15:25:35 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 
# include "./ft_printf.h"
# include "./libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
	int				index;
}	t_stack;

t_stack	*parse_stack(int count, char **list);
void	print_stack(t_stack *stack);
t_stack	*create_stack(t_stack *prev);
void	*free_stack(t_stack *stack);
t_stack	*get_head(t_stack *stack);
t_stack	*get_queue(t_stack *stack);
void	*exit_error(t_stack *stack, char *message);
int		get_size(t_stack *stack);
int		get_max_bits(int size);
t_stack	*sort_stack(t_stack *stack_a);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a);
void	sort_five(t_stack *stack_a);
void	radix_sort(t_stack *stack_a, int size, int max_bits);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);

#endif
