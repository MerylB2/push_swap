/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:42:35 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/30 19:53:29 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"
/*
** --- SWAP OPERATIONS ---
** Échange les 2 premiers éléments au sommet de la pile
** Ne fait rien s'il n'y en a qu'un ou aucun
*/
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_s(t_stack *a, t_stack *b);

/*
** --- PUSH OPERATIONS ---
** Prend le premier élément au sommet d'une pile et le met sur l'autre pile
** Ne fait rien si la pile d'origine est vide
*/
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

/*
** --- ROTATE OPERATIONS ---
** Décale d'une position vers le haut tous les éléments de la pile
** Le premier élément devient le dernier
*/
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_r(t_stack *a, t_stack *b);

/*
** --- REVERSE ROTATE OPERATIONS ---
** Décale d'une position vers le bas tous les éléments de la pile
** Le dernier élément devient le premier
*/
void	rotate_rev_a(t_stack *a);
void	rotate_rev_b(t_stack *b);
void	rotate_rev_r(t_stack *a, t_stack *b);

/*
** --- UTILS ---
** Fonctions utilitaires pour les opérations
*/
void	print_operation(char *op);
int		is_valid_operation(char *op);
void	execute_op(t_stack *a, t_stack *b, char *op);

/*
** --- BONUS OPERATIONS ---
** Versions silencieuses des opérations pour le checker
** Ces fonctions font la même chose mais n'affichent pas l'opération
*/

#endif