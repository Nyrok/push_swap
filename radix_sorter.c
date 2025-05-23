/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/05/20 15:25:35 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	assign_indexes(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		index;

	tmp1 = stack;
	while (tmp1)
	{
		index = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp2->value < tmp1->value)
				index++;
			tmp2 = tmp2->next;
		}
		tmp1->radix_index = index;
		tmp1 = tmp1->next;
	}
}

int	find_lowest_index(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack && stack->radix_index != 0)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

t_stack	*min_node(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}

void	radix_sort(t_stack *stack_a, int size, int max_bits)
{
	t_stack	*tmp;
	t_stack	*stack_b;
	int		i;
	int		j;

	i = 0;
	stack_b = NULL;
	assign_indexes(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			tmp = get_head(stack_a);
			if (((tmp->radix_index >> i) & 1) == 0)
				pb(&stack_a, &stack_b);
			else
				ra(&stack_a);
			j++;
		}
		while (stack_b)
			pa(&stack_a, &stack_b);
		i++;
	}
}
