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

t_stack	*parse_stack(int count, char **list)
{
	t_stack	*stack;
	t_stack	*prev_stack;
	int		i;
	int		*parsed_value;

	i = 1;
	prev_stack = NULL;
	while (i < count)
	{
		stack = create_stack(prev_stack);
		if (!stack)
			return (NULL);
		parsed_value = ft_atoi(list[i]);
		if (!parsed_value)
		{
			free(stack);
			return (NULL);
		}
		stack->value = *parsed_value;
		free(parsed_value);
		prev_stack = stack;
		i++;
	}
	return (stack);
}
