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
	t_list	**stack_b;
	int	i;

	if (argv > 1)
	{
		stack_a = stack_factory('a');
		stack_b = stack_factory('b');
		i = 1;
		while (i < argv)
		{
			if (!ft_create_stack(stack_a, argc[i]))
				printf("Error\n");
			i++;
		}
		ft_lstprnt(*stack_factory('a'));
		choose_algorithm(--argv);
		ft_lstprnt(*stack_factory('a'));
	
	}
}

void	choose_algorithm(int elements)
{
	if (elements == 2)
		hardcoded_2();
	else if (elements == 3)
		hardcoded_3();
}

t_list	**stack_factory(char c)
{
	static	t_list *stack_a;
	static	t_list *stack_b;

	if (c == 'a')
		return (&stack_a);
	if (c == 'b')
		return (&stack_b);
	return (NULL);
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
/*void	test_moves()
{
		ft_lstprnt(*(stack_factory('a')));
		swap_a('a');
		printf("\nSWAPPED A\n");
		ft_lstprnt(*(stack_factory('a')));
		fflush(stdout);
		printf("\n\nPUSHED B\nA: ");
		fflush(stdout);
		push_b();
		ft_lstprnt(*(stack_factory('a')));
		printf("\nB: ");
		fflush(stdout);
		ft_lstprnt(*(stack_factory('b')));
		printf("\n");
		printf("\nROTATING A: \n");
		fflush(stdout);
		rotate_a();
		ft_lstprnt(*(stack_factory('a')));
		printf("\n");
		printf("\nROTATING B: \n");
		fflush(stdout);
		rotate_b();
		ft_lstprnt(*(stack_factory('b')));
		printf("\n");
		printf("\nROTATING BOTH: \nA: ");
		fflush(stdout);
		rr();
		ft_lstprnt(*(stack_factory('a')));
		printf("\nB: ");
		fflush(stdout);
		ft_lstprnt(*(stack_factory('b')));
		printf("\n");
		printf("\n\nPUSHED B\nA: ");
		fflush(stdout);
		push_b();
		ft_lstprnt(*(stack_factory('a')));
		printf("\nB: ");
		fflush(stdout);
		ft_lstprnt(*(stack_factory('b')));
		printf("\n");
		printf("\n\nPUSHED B\nA: ");
		fflush(stdout);
		push_b();
		ft_lstprnt(*(stack_factory('a')));
		printf("\nB: ");
		fflush(stdout);
		ft_lstprnt(*(stack_factory('b')));
		printf("\n");
		printf("\nROTATING BOTH: \nA: ");
		fflush(stdout);
		rr();
		ft_lstprnt(*(stack_factory('a')));
		printf("\nB: ");
		fflush(stdout);
		ft_lstprnt(*(stack_factory('b')));
		printf("\n");
		printf("\nREVERSE ROTATING BOTH: \nA: ");
		fflush(stdout);
		rrr();
		ft_lstprnt(*(stack_factory('a')));
		printf("\nB: ");
		fflush(stdout);
		ft_lstprnt(*(stack_factory('b')));
		printf("\n");


}*/
