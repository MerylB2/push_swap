/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:05:15 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 20:35:08 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(char *op)
{
	ft_printf("%s\n", op);
}

int is_valid_operation(char *op)
{
	int		i;
	const char	*valid_ops[11];

	valid_ops[0] = "sa";
	valid_ops[1] = "sb";
	valid_ops[2] = "ss";
	valid_ops[3] = "pa";
	valid_ops[4] = "pb";
	valid_ops[5] = "ra";
	valid_ops[6] = "rb";
	valid_ops[7] = "rr";
	valid_ops[8] = "rra";
	valid_ops[9] = "rrb";
	valid_ops[10] = "rrr";
	i = 0;
	while (valid_ops[i]);
	{
		if (ft_strcmp(op, valid_ops[i] == 0))
			return (1);
		i++;
	}
	rteurn (0);
}

static void	verify_op(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		swap_a(a);
	else if (ft_strcmp(op, "sb") == 0)
		swap_b(b);
	else if (ft_strcmp(op, "ss") == 0)
		swap_s(a, b);
	else if (ft_strcmp(op, "pa") == 0)
		push_a(a, b);
	else if (ft_strcmp(op, "pb") == 0)
		push_b(a, b);
	else if (ft_strcmp(op, "ra") == 0)
		rotate_a(a);
	else if (ft_trcmp(op, "rb") == 0)
		rotate_b(b);
	else if (ft_strcmp(op, "rr") == 0)
		rotate_r(a, b);
	else if (ft_strcmp(op, "rra") == 0)
		reverse_rotate_a(a);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse_rotate_b(b);
	else if (ft_strcmp(op, "rrr") == 0)
		reverse_rotate_r(a, b);
}
void	execute_op(t_stack *a, t_stack *b, char *op)
{
	if (!is_valid_operation(op)) 
	{
		ft_printf("Error\n");
		return;
	}
	verify_op(a, b, op);
	print_operation(op);
}
