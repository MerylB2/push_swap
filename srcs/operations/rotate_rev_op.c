/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:07:08 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 20:04:39 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rev_a(t_stack *a)
{
	t_node	*last;
	t_node	*prev;

	if (!a || !a->head || !a->head->next)
		return;
	last = a->head;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = a->head;
	a->head = last;
}

void	rotate_rev_b(t_stack *b)
{
	t_node	*last;
	t_node	*prev;

	if (!b || !b->head || !b->head->next)
		return;
	last = b->head;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = b->head;
	b->head = last;
}

void	rotate_rev_r(t_stack *a, t_stack *b)
{
	rotate_rev_a(a);
	rotate_rev_b(b);
}
