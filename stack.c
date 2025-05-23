/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/05/20 15:25:35 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stack	*create_stack(t_stack *prev)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->prev = prev;
	stack->next = NULL;
	stack->radix_index = 0;
	if (prev)
		prev->next = stack;
	return (stack);
}

t_stack	*get_head(t_stack *stack)
{
	while (stack && stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*get_queue(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

int	get_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
