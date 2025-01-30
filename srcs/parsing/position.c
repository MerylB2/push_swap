/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:13:54 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 19:22:42 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target(t_stack *a, t_node *current_b, int *t_pos, long *c_big)
{
	t_node	*current_a;
	int		pos;

	current_a = a->head;
	pos = 0;
	while (current_a)
	{
		if (current_a->value > current_b->value && current_a->value < *c_big)
		{
			*c_big = current_a->value;
			*t_pos = pos;
		}
		pos++;
		current_a = current_a->next;
	}
}

static int	find_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min_pos;
	long	min_val;
	int		pos;

	current = stack->head;
	min_val = LONG_MAX;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	get_position(t_stack *stack)
{
	t_node	*current;
	int		pos;

	if (!stack || !stack->head)
		return;
	current = stack->head;
	pos = 0;
	while (current)
	{
		current->pos = pos;
		pos++;
		current = current->next;
	}
}

void	get_target_position(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	int		target_pos;
	long	closest_bigger;

	current_b = b->head;
	while (current_b)
	{
		closest_bigger = LONG_MAX;
		find_target(a, current_b, &target_pos, &closest_bigger);
		if (closest_bigger == LONG_MAX)
			current_b->target_pos = find_min_pos(a);
		else
			current_b->target_pos = target_pos;
		current_b = current_b->next;
	}
}
