/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:59:55 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 17:21:19 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_pos(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		min_pos;
	int		pos;

	current = stack->head;
	min = current->value;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static int 	move_smallest_to_top(t_stack *stack, int min_pos)
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
	return (1);
}

void	sort_small(t_data *data)
{
	int	min_pos;

	while (data->stack_a->size > 3)
	{
		min_pos = find_smallest_pos(data->stack_a);
		move_smallest_to_top(data->stack_a, min_pos);
		push_b(data->stack_b, data->stack_a, 1);
	}
	sort_three(data->stack_a);
	while (data->stack_b->size > 0)
		push_a(data->stack_a, data->stack_b, 1);
}
