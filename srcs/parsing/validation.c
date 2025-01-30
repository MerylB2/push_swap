/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:12:24 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 13:41:16 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(int argc, char **argv, t_data *data)
{
	int			i;
	long long	nb;
	t_node		*new_node;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			error_exit(data, ERR_ARGS);
		nb = ft_atoll(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_exit(data, ERR_OVERFLOW);
		new_node = create_node((int)nb);
		if (!new_node)
			error_exit(data, ERR_MALLOC);
		add_node_back(data->stack_a, new_node);
		i++;
	}
}

int	is_valid_number(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	check_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->head;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if(current->value == check->value)
				error_exit(NULL, ERR_DUP);
			check = check->next;
		}
		current = current->next;
	}

}

void	index_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*min;
	int		index;

	index = 0;
	while (index < stack->size)
	{
		current = stack->head;
		min = NULL;
		while (current)
		{
			if (current->index == -1 && (min || current->value < min->value))
				min = current;
			current = current->next;
		}
		if (min)
			min->index = index;
		index++;
	}
}