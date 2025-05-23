/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/05/20 15:25:35 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			ra(&stack_a);
	}
}

void	sort_three(t_stack *stack_a)
{
	sort_two(stack_a);
}

void	sort_four(t_stack *stack_a)
{
	(void)stack_a;
}

void	sort_five(t_stack *stack_a)
{
	(void)stack_a;
}

t_stack	*sort_stack(t_stack *stack_a)
{
	int		max_bits;
	int		size;

	size = get_size(stack_a);
	max_bits = get_max_bits(size);
	if (size > 5)
		radix_sort(stack_a, size, max_bits);
	else if (size > 4)
		sort_five(stack_a);
	else if (size > 3)
		sort_four(stack_a);
	else if (size > 2)
		sort_three(stack_a);
	else if (size > 1)
		sort_two(stack_a);
	return (stack_a);
}
