/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/05/20 15:25:35 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = get_queue(*stack);
	before_last = last->prev;
	before_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
	return (1);
}

int	rotate(t_stack **stack)
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

int	push(t_stack **from, t_stack **to)
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

int	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
	return (1);
}
