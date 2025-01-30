/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:21:50 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 17:35:09 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos_from_head(t_stack *stack)
{
	int		min_pos;
	int		pos;
	t_node	*current;

	current = stack->head;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < stack->head->value)
			min_pos = pos;
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static void	rotate_to_min(t_stack *stack, int min_pos)
{
	while (min_pos > 0)
	{
		if (min_pos <= stack->size / 2)
		{
			rotate_a(stack, 1);
			min_pos--;
		}
		else
		{
			rotate_rev_a(stack, 1);
			min_pos++;
		}
	}
}

void    sort_large(t_data *data)
{
	int	min_pos;

	while (data->stack_a->size > 3)
	{
		get_position(data->stack_a);
		get_target_position(data->stack_a, data->stack_b);
		calculate_cost(data->stack_a, data->stack_b);
		execute_cheapest_move(data);
	}
	if (!is_sorted(data->stack_a))
		sort_three(data->stack_a);
	get_position(data->stack_a);
	get_position(data->stack_b);
	
	while (data->stack_b->size > 0)
	{
		get_target_position(data->stack_b, data->stack_a);
		calculate_cost(data->stack_b, data->stack_a);
		execute_cheapest_move(data);
	}
	min_pos = find_min_pos_from_head(data->stack_a);
	rotate_to_min(data->stack_a, min_pos);
}