/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:03:42 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 19:56:18 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !a->head || !a->head->next)
		return ;
	if (a->size < 2)
		return ;
	first = a->head;
	second = a->head->next;
	first->next = second->next;
	second->next= first;
	a->head = second;
}

void	swap_b(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || !b->head || !b->head->next)
		return ;
	if (b->size < 2)
		return ;
	first = b->head;
	second = b->head->next;
	first->next = second->next;
	second->next= first;
	b->head = second;
}

void	swap_s(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
}
