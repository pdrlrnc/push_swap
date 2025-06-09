/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortihms_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:23:01 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/09 13:23:03 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	hardcoded_2()
{
	t_list	**stack_a;

	stack_a = stack_factory('a');
	if (*((int *)(*stack_a)->content) > *((int *)((*stack_a)->next)->content))
		swap_a();
}

void	hardcoded_3()
{
	t_list	**stack_a;
	int	first;
	int	second;
	int	third;

	stack_a = stack_factory('a');
	first = *((int *)(*stack_a)->content);
	second = *((int *)(*stack_a)->next->content);
	third = *((int *)(*stack_a)->next->next->content);
	if ((first <= second) && (second <= third))
		return ;
	if (first > second)
	{
		if (second > third)
			swap_a();
		else if (first > third)
			rotate_a();
		else
			swap_a();
	}
	else
		rra();
	hardcoded_3();
}
