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

	stack_a = stack_factory('a');
	stack_b = stack_factory('b');
	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
		write (1, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	push_b()
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*temp;

	stack_a = stack_factory('a');
	stack_b = stack_factory('b');
	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
		write (1, "pb\n", 3);
		return (1);
	}
	return (0);
}
