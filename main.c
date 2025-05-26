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
	int		is_from_argv;

	is_from_argv = 1;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		is_from_argv = 0;
	}
	if (!argv)
		return (exit_error(NULL), EXIT_FAILURE);
	stack = parse_stack(argc, argv, is_from_argv);
	if (!is_from_argv)
		free_split(argv);
	stack = get_head(stack);
	if (!stack)
		return (EXIT_FAILURE);
	stack = sort_stack(stack);
	stack = get_head(stack);
	free_stack(stack);
}
