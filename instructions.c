/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/05/20 15:25:35 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a))
		ft_putendl_fd("pa", STDOUT_FILENO);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b))
		ft_putendl_fd("pb", STDOUT_FILENO);
}

void	ra(t_stack **stack_a)
{
	if (rotate(stack_a))
		ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a))
		ft_putendl_fd("rra", STDOUT_FILENO);
}

void	sa(t_stack **stack_a)
{
	if (swap(stack_a))
		ft_putendl_fd("sa", STDOUT_FILENO);
}
