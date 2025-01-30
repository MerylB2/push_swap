/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:07:13 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 20:00:09 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *a)
{
	t_node	*first;
	t_node	*current;

	if (!a || !a->head || !a->head->next)
		return;
	first = a->head;
	a->head = a->head->next;
	current = a->head;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
}

void	rotate_b(t_stack *b)
{
	t_node	*first;
	t_node	*current;

	if (!b || !b->head || !b->head->next)
		return;
	first = b->head;
	b->head = b->head->next;
	current = b->head;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
}

void	rotate_r(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
}