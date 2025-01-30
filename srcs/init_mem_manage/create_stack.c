/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:48:35 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 11:59:41 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_program(t_data *data)
{
	if (!data)
		error_exit(NULL, ERR_MALLOC);
	data->stack_a = create_stack('a');
	data->stack_b = create_stack('b');
	if (!data->stack_a || !data->stack_b)
		error_exit(data, ERR_MALLOC);
	data->total_size = 0;
	data->min_value = INT_MAX;
	data->max_value = INT_MIN;
}

t_stack	*create_stack(char name)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->size = 0;
	new_stack->name = name;
	return(new_stack);
}

void	error_exit(t_data *data, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	else
		write(2, "Error\n", 6);
	if (data)
		free_program(data);
	exit (1);
}
