/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/05/20 15:25:35 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	value;

	if (!stack)
		return (1);
	value = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (value > stack->value)
			return (0);
		value = stack->value;
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		exit_error(NULL);
	stack = parse_stack(argc, argv);
	stack = get_head(stack);
	if (!stack)
		return (1);
	stack = sort_stack(stack);
	stack = get_head(stack);
	free_stack(stack);
	return (0);
}
