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
	t_list	**stack_b;

	stack_a = stack_factory('a');
	stack_b = stack_factory('b');
	if (*((int *)(*stack_a)->content) > *((int *)((*stack_a)->next)->content))
		swap_a();
}
