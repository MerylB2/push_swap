/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:23:11 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 20:37:17 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish_rotation(t_stack *stack, int cost, char stack_name)
{
	while (cost > 0)
	{
		if (stack_name == 'a')
			rotate_a(stack);
		else
			rotate_b(stack);
		cost--;
	}
	while (cost < 0)
	{
		if (stack_name == 'a')
			rotate_rev_a(stack);
		else
			rotate_rev_b(stack);
		cost++;
	}
}

static void	execute_move(t_data *data, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rotate_r(data->stack_a, data->stack_b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rotate_rev_r(data->stack_a, data->stack_b);
		cost_a++;
		cost_b++;
	}
	finish_rotation(data->stack_a, cost_a, 'a');
	finish_rotation(data->stack_b, cost_b, 'b');
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		size_a;
	int		size_b;

	current = b->head;
	size_a = a->size;
	size_b = b->size;
	while (current)
	{
		current->cost_b = current->pos;
		if (current->pos > size_b / 2)
			current->cost_b = -(size_b - current->pos);
		
		current->cost_a = current->target_pos;
		if (current->target_pos > size_a / 2)
			current->cost_a = -(size_a - current->target_pos);
		current = current->next;
	}
}

void	execute_cheapest_move(t_data *data)
{
	t_node	*current;
	t_node	*cheapest;
	int		lowest_cost;

	current = data->stack_b->head;
	cheapest = current;
	lowest_cost = abs(current->cost_a) + abs(current->cost_b);

	while (current)
	{
		if (abs(current->cost_a) + abs(current->cost_b) < lowest_cost)
		{
			lowest_cost = abs(current->cost_a) + abs(current->cost_b);
			cheapest = current;
		}
		current = current->next;
	}
	
	execute_move(data, cheapest->cost_a, cheapest->cost_b);
	push_a(data->stack_a, data->stack_b);
}
