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

void	sort_two(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;

	assign_indexes(*stack_a);
	pos = find_lowest_index(*stack_a);
	if (pos == 1)
		ra(stack_a);
	else if (pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (pos == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (*stack_a != min_node(*stack_a))
	{
		rra(stack_a);
	}
	pb(stack_a, &stack_b);
	sort_four(stack_a, &stack_b);
	pa(stack_a, &stack_b);
}

t_stack	*sort_stack(t_stack *stack_a)
{
	int		max_bits;
	int		size;
	t_stack	*stack_b;

	stack_b = NULL;
	if (is_sorted(stack_a))
		return (stack_a);
	size = get_size(stack_a);
	max_bits = get_max_bits(size);
	if (size > 5)
		radix_sort(stack_a, size, max_bits);
	else if (size > 4)
		sort_five(&stack_a);
	else if (size > 3)
		sort_four(&stack_a, &stack_b);
	else if (size > 2)
		sort_three(&stack_a);
	else if (size > 1)
		sort_two(&stack_a);
	return (stack_a);
}
