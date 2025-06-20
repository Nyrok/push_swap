/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/05/20 15:25:35 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	ft_fullisdigit(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (!len || len >= 12)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	check_unique(t_stack *stack)
{
	t_stack	*prev;
	int		value;

	if (!stack)
		return (1);
	value = stack->value;
	stack = stack->prev;
	prev = stack;
	while (stack)
	{
		if (stack->value == value)
			return (0);
		stack = stack->prev;
	}
	return (check_unique(prev));
}

static void	*parse_error(t_stack *stack, char **list, int is_from_argv)
{
	if (!is_from_argv)
		free_split(list);
	return (exit_error(stack));
}

t_stack	*parse_stack(int count, char **list, int is_from_argv)
{
	t_stack		*stack;
	t_stack		*prev_stack;
	long int	parsed_value;
	int			i;

	stack = NULL;
	i = is_from_argv;
	prev_stack = NULL;
	while (i < count)
	{
		stack = create_stack(prev_stack);
		if (!stack)
			return (parse_error(prev_stack, list, is_from_argv));
		if (!ft_fullisdigit(list[i]))
			return (parse_error(stack, list, is_from_argv));
		parsed_value = ft_atoi(list[i]);
		if (parsed_value < -2147483648 || parsed_value > 2147483647)
			return (parse_error(stack, list, is_from_argv));
		stack->value = parsed_value;
		prev_stack = stack;
		i++;
	}
	if (!check_unique(stack))
		return (parse_error(stack, list, is_from_argv));
	return (stack);
}
