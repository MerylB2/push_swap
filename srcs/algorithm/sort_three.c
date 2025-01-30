/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:42:27 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 16:57:25 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_data *data)
{
	if (!data || !data->stack_a || !data->stack_b)
		return ;
	if (data->total_size == 2)
	{
		if (data->stack_a->head->value > data->stack_a->head->next->value)
			swap_a(data->stack_a, 1);
		return ;
	}
	if (data->total_size == 3)
		sort_three(data->stack_a);
	else if (data->total_size <= 5)
		sort_small(data);
	else
		sort_large(data);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->head->value;
	second = stack->head->next->value;
	third = stack->head->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(stack, 1);
	else if (first > second && second > third)
	{
		swap_a(stack, 1);
		rotate_rev_a(stack, 1);
	}
	else if (first > second && second < third && first > third)
		rotate_a(stack, 1);
	else if (first < second && second > third && first < third)
	{
		swap_a(stack, 1);
		rotate_a(stack, 1);
	}
	else if (first < second && second > third && first > third)
		rotate_rev_a(stack, 1);
}

