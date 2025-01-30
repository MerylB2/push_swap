/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:54:34 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 19:36:59 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "operations.h"

/*
** Messages d'erreur
*/
# define ERR_MALLOC "Error: Memory allocation failed\n"
# define ERR_ARGS "Error: Invalid arguments\n"
# define ERR_DUP "Error: Duplicate numbers found\n"
# define ERR_OVERFLOW "Error: Number overflow\n"

/*
** Structure du nœud de la pile
*/
typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct  s_node 	*next;
}	t_node;

/*
** Structure de la pile
*/
typedef struct s_stack
{
	t_node	*head;
	char	name;
	int		size;
}	t_stack;

/*
** Structure principale
*/
typedef struct s_data
{
	t_stack *stack_a;
	t_stack	*stack_b;
	int		total_size;
	int		min_value;
	int		max_value;
}	t_data;

/*
** Fonctions d'initialisation et de gestion de la mémoire
*/
void	init_program(t_data *data);
t_stack	*create_stack(char name);
void	free_program(t_data *data);
void	free_stack(t_stack *stack);
void	error_exit(t_data *data, char msg);

/*
** Fonctions de parsing et validation
*/
void	parse_args(int argc, char **argv, t_data *data);
int		is_valid_number(char *str);
long long	ft_atoll(const char *str);
void	check_duplicates(t_stack *stack);
void	index_stack(t_stack *stack);

/*
** Fonctions pour l'algorithme de tri
*/
void	sort_stack(t_data *data);
void	sort_three(t_stack *stack);
void	sort_small(t_data *data);
void	sort_large(t_data *data);

/*
** Fonctions de calcul des positions et coûts
*/
void	get_position(t_stack *stack);
void	get_target_position(t_stack *a, t_stack *b);
void	calculate_cost(t_stack *a, t_stack *b);
void	execute_cheapest_move(t_data *data);

/*
** Fonctions utilitaires
*/
int		is_sorted(t_stack *stack);
int		get_distance(t_stack *stack, int index);
void	print_stacks(t_data *data);
int		get_min_index_position(t_stack *stack);
void	rote_to_min(t_data *data);

/*
** Fonctions de debug (activées avec -DDEBUG)
*/
# ifdef DEBUG
void	debug_print_stacks(t_data *data);
void	debug_print_costs(t_stack *a, t_stack *b);
void	debug_print_move(char *operation);
# endif

#endif
