/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:39:58 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/11 16:39:59 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*normalize_input(void)
{
	int	*normalized;
	int	i;
	int	j;
	t_list	*stack_a;
	t_list	*stack_a_cpy;

	stack_a = *stack_factory('a');
	bubble_sort_cpy();
	normalized = malloc(sizeof(int) * ft_lstsize(stack_a));
	if (!normalized)
		return (NULL);
	j = 0;
	while (stack_a)
	{
		i = 0;
		stack_a_cpy = *stack_factory('c');
		while (stack_a_cpy)
		{
			if ((*(int *)stack_a_cpy->content) == (*(int *)stack_a->content))
				break;
			i++;
			stack_a_cpy = stack_a_cpy->next;
		}
		*(normalized + j) = i;
		j++;
		stack_a = stack_a->next;
	}
	return (normalized);
}

void	chunked_insertion_sort(int chunk_size)
{
	int	*normalized;
	int	chunk_min;
	int	chunk_max;
	int	lst_size;
	int	curr_size;
	int	i;
	int	found;
	int	top;
	int	first;

	normalized = normalize_input();
	if (!normalized)
		return ;
	lst_size = ft_lstsize(*stack_factory('a'));
	chunk_max = lst_size - 1;
	first = 1;
	while (chunk_max >= 0)
	{
		chunk_min = ((chunk_max - chunk_size) + 1);
		if (chunk_min < 0)
			chunk_min = 0;
		i = 0;
		curr_size = lst_size;
		found = 0;
		while ((i < curr_size) && (found < chunk_size))
		{
			if (*(normalized + i) >= chunk_min && *(normalized + i) <= chunk_max)
			{
				top = (*normalized);
				found_value(i, curr_size, &normalized, top, first);
				curr_size--;
				found++;
				i = -1;
			}
			i++;
		}
		first = 0;
		chunk_max -= chunk_size;
		push_back(&normalized, curr_size, found);
	}
	free(normalized);
	
}

void	push_back(int **normalized, int size, int elems)
{
	int	max_index;
	int	*res;
	int	aux;
	int	i;
	static int norm_index;

	aux = elems;
	res = malloc(sizeof(int) * (size + elems));
	if (!res)
		return ;
	while (aux--)
	{
		max_index = get_max_index('b');
		if ((max_index / 2) < aux)
			while (max_index--)
				rotate_b();
		else
			while (max_index++ < aux)
				rrb();
		push_a();
	}
	aux = 0;
	while (aux < elems)
		*(res + aux++) = --norm_index;
	i = 0;
	while (aux < (size + elems))
		*(res + aux++) = (*normalized)[i++];
	free(*normalized);
	*normalized = res;
}

static void	push_b_norm(int **normalized, int size)
{
	int	*result;
	int	i;
	int	j;

	result = malloc(sizeof(int) * (size - 1));
	if (!result)
		return ;
	i = 0;
	j = 1;
	while (i < (size - 1))
	{
		*(result + i) = (*normalized)[j];
		i++;
		j++;
	}	
	free(*normalized);
	*normalized = result;
}

static void	reverse_rotate_normalization(int **normalized, int size)
{
	int	i;
	int	aux;

	aux = (*normalized)[size - 1];
	i = size - 2;
	while (i >= 0)
	{
		(*normalized)[i + 1] = (*normalized)[i];
		i--;
	}
	(*normalized)[0] = aux;
}
static void	rotate_normalization(int **normalized, int size)
{
	int	i;
	int	aux;

	aux = (*normalized)[0];
	i = 1;
	while (i < size)
	{
		(*normalized)[i - 1] = (*normalized)[i];
		i++;
	}
	(*normalized)[size - 1] = aux;
}

void	found_value(int i, int size, int **normalized, int top, int first)
{
	int	rotations;
	
	rotations = 0;
	if (i <= (size / 2))
	{
		while (i--)
		{
			rotations++;
			rotate_a();
			rotate_normalization(normalized, size);
		}
	}
	else
	{
		while (i++ < size)
		{
			rotations--;
			rra();
			reverse_rotate_normalization(normalized, size);
		}
	}
	push_b();
	push_b_norm(normalized, size);
	size--;
	if (!first)
		rearrange(rotations, normalized, size, top);
}

void	rearrange(int rotations, int **normalized, int size, int top)
{
	if (rotations > 0)
	{
		while ((*normalized)[0] != top)
		{
			rra();
			reverse_rotate_normalization(normalized, size);
		}
	}
	else if (rotations < 0)
	{
		while ((*normalized)[0] != top)
		{
			rotate_a();
			rotate_normalization(normalized, size);
		}
	}
}
