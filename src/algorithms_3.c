/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:07:59 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/24 14:08:00 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix(void)
{
	int	size;
	int	max;
	int	bits;
	int	i;

	size = ft_lstsize(*stack_factory('a'));
	max = get_max_index();
	bits = 0;
	while ((max >> bits) != 0)
	{
		i = 0;
		while (i < size)
		{
			if ((*((int *)(*stack_factory('a'))->content) >> bits & 1) == 0)
				push_b();
			else
				rotate_a();
			i++;
		}
		while (ft_lstsize(*(stack_factory('b'))))
			push_a();
		bits++;
		if (is_ordered('a'))
			return ;
	}
}

int	get_max_index(void)
{
	t_list	*stack;
	int		max;

	stack = *(stack_factory('a'));
	max = *(int *)stack->content;
	while (stack)
	{
		if (max < *(int *)stack->content)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}
