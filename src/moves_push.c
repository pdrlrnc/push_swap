/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:44:46 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/08 13:44:47 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_a()
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*temp;
	char	*move;

	move = malloc(4);
	if (!move)
		return (0);
	*move = 'p';
	*(move + 1) = 'a';
	*(move + 2) = '\n';
	*(move + 3) = '\0';
	stack_a = stack_factory('a');
	stack_b = stack_factory('b');
	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
		add_move(move);
		return (1);
	}
	return (0);
}

int	push_b()
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*temp;
	char	*move;

	move = malloc(4);
	if (!move)
		return (0);
	*move = 'p';
	*(move + 1) = 'b';
	*(move + 2) = '\n';
	*(move + 3) = '\0';
	stack_a = stack_factory('a');
	stack_b = stack_factory('b');
	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
		add_move(move);
		return (1);
	}
	free(move);
	return (0);
}
