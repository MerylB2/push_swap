/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:07:21 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 19:57:50 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	t_node	*push;

	if (!b || !b->head)
		return ;
	if (b->size == 0)
		return ;
	push = b->head;
	b->head = b->head->next;
	b->size--;
	push->next = a->head;
	a->head = push;
	a->size++;
}

void	push_b(t_stack *b, t_stack *a)
{
	t_node	*push;

	if (!a || !a->head)
		return ;
	if (a->size == 0)
		return ;
	push = a->head;
	a->head = a->head->next;
	a->size--;
	push->next = b->head;
	b->head = push;
	b->size++;
}
