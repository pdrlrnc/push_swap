/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:03:17 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/28 15:03:18 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argv, char **argc)
{
	t_list	**stack_a;
	int	i;

	if (argv > 1)
	{
		stack_a = stack_factory('a');
		i = 1;
		while (i < argv)
		{
			if (!ft_create_stack(stack_a, argc[i]))
				printf("Error\n");
			i++;
		}
		ft_lstprnt(*stack_a);
		swap_a('a');
		printf("\nSWAPPED\n");
		ft_lstprnt(*(stack_factory('a')));
	}
}

t_list	**stack_factory(char c)
{
	static	t_list *stack_a;
	static	t_list *stack_b;

	if (c == 'a')
		return (&stack_a);
	else
		return (&stack_b);
}

int	ft_create_stack(t_list **stack, char *argc)
{
	int	*nb;

	if (ft_check_if_zero(argc))
	{
		nb = malloc(sizeof(int));
		if (!nb)
			return (0);
		*nb = 0;
		if (*stack == NULL)
			*stack = ft_lstnew(nb);
		else
			ft_lstadd_back(&(*stack), ft_lstnew(&nb));
	}
	else
	{
		nb = malloc(sizeof(int));
		if (!nb)
			return (0);
		*nb = ft_atoi(argc);
		if (*nb == 0)
			return (free(nb), 0);
		if (stack == NULL)
			*stack = ft_lstnew(nb);
		else
			ft_lstadd_back(&(*stack), ft_lstnew(nb));
	}
	if (!*stack)
		return (free(nb),(0));
	return (1);
}
