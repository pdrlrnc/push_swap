/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:14:52 by pedde-so          #+#    #+#             */
/*   Updated: 2025/08/20 13:14:53 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bubble_sort_arr(int *arr, int size)
{
	int	aux;
	int	done;
	int	i;

	done = 0;
	while (!done)
	{
		done = 1;
		i = 0;
		while (i < (size - 1))
		{
			if (*(arr + i) > *(arr + i + 1))
			{
				aux = *(arr + i);
				*(arr + i) = *(arr + i + 1);
				*(arr + i + 1) = aux;
				done = 0;
			}
			i++;
		}
	}
}
