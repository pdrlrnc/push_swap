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
#include <stdio.h>

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
	int	debug_iteration;

	normalized = normalize_input();
	if (!normalized)
		return ;
	lst_size = ft_lstsize(*stack_factory('a'));
	chunk_max = lst_size - 1;
	debug_iteration = 0;
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
				found_value(i, curr_size, &normalized);
				curr_size--;
				found++;
				i = -1;
			}
			i++;
		}
		printf("\n\n\t\t->DEBUG: ITERATION %d, A:", debug_iteration);
		fflush(stdout);
		ft_lstprnt(*stack_factory('a'));
		printf("\n\t\t->B:");
		fflush(stdout);
		ft_lstprnt(*stack_factory('b'));
		chunk_max -= chunk_size;
		push_back(&normalized, curr_size, found);
		printf("\n\n\t\t->DEBUG: ITERATION %d, [AFTER PUSH_BACK] A:", debug_iteration);
		fflush(stdout);
		ft_lstprnt(*stack_factory('a'));
		printf("\n\t\t->B:");
		fflush(stdout);
		ft_lstprnt(*stack_factory('b'));

		debug_iteration++;
	}
	write(1, "\nAfter Chunk\n A:", 16);
	ft_lstprnt(*stack_factory('a'));
	write(1, "\nB:", 3);
	ft_lstprnt(*stack_factory('b'));
	free(normalized);
	
}

void	push_back(int **normalized, int size, int elems)
{
	int	max_index;
	int	*res;
	int	aux;
	int	i;

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
		*(res + aux++) = INT_MAX;
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


	write(1, "\nAfter PushB\n N: [", 18);
	i = 0;
	while ( i < (size - 1))
	{
		ft_putnbr_fd(*(result + i), 1);
		i++;
		if (i < (size - 1))
			write(1, " ,", 2);
	}
	write(1, "]\n\n", 3);

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

	fprintf(stderr, " about to rotate %p of length %d\n",
	(void*)*normalized, size);

	
	aux = (*normalized)[0];
	i = 1;
	while (i < size)
	{
		(*normalized)[i - 1] = (*normalized)[i];
		i++;
	}
	(*normalized)[size - 1] = aux;
}

void	found_value(int i, int size, int **normalized)
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
	rearrange(rotations, normalized, size);
}

void	rearrange(int rotations, int **normalized, int size)
{
	if (rotations > 0)
	{
		while (rotations--)
		{
			rra();
			reverse_rotate_normalization(normalized, size);
		}
	}
	else
	{
		while (rotations++)
		{
			rotate_a();
			rotate_normalization(normalized, size);
		}
	}
}
