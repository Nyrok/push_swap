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

static int	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = get_head(*stack);
	last = get_queue(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	return (1);
}

static int	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	*from = get_head(*from);
	*to = get_head(*to);
	if (!from || !*from)
		return (0);
	tmp = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	tmp->next = *to;
	tmp->prev = NULL;
	if (*to)
		(*to)->prev = tmp;
	*to = tmp;
	return (1);
}

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
