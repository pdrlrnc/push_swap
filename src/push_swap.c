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

int	main(int argv, char **argc)
{
	int	i;
	char	**inputs;
	int	valid;

	if (argv > 1)
	{
		valid = 1;
		if (argv == 2)
		{
			i = 0;
			inputs = ft_split(argc[1], ' ');
			while (inputs[i] != NULL && valid)
			{
				if(!ft_create_stack(inputs[i]))
				{	
					valid = 0;
					write(1, "Error\n", 6);
				}
				i++;
			}
			argv = i + 1;
		}
		else
		{
			i = 1;
			while (i < argv && valid)
			{
				if (!ft_create_stack(argc[i]))
				{
					valid = 0;
					write(1, "Error\n", 6);
				}
				i++;
			}
		}
		if (valid && ft_input_is_valid())
		{
			choose_algorithm(--argv);
		}
		ft_lstclear(stack_factory('a'), free);
		ft_lstclear(stack_factory('b'), free);
		//ft_lstclear(stack_factory('c'), free);
	}
}

int	ft_input_is_valid(void)
{
	t_list	*inner_stack;
	t_list	*outter_stack;

	outter_stack = *(stack_factory('a'));
	while (outter_stack)
	{
		inner_stack = outter_stack->next;
		while (inner_stack)
		{
			if (*(int *)(outter_stack->content) == *(int *)(inner_stack->content))
				return (write(1, "Error\n", 6), 0);
			inner_stack = inner_stack->next;
		}
		outter_stack = outter_stack->next;
	}
	return (1);
}

void	choose_algorithm(int elements)
{
	if (elements == 2)
		hardcoded_2();
	else if (elements == 3)
		hardcoded_3();
	else if (elements == 4)
	 	hardcoded_4();
	else if (elements == 5)
		hardcoded_5();
	else if (elements < 100)
		chunked_insertion_sort();
}

t_list	**stack_factory(char c)
{
	static	t_list *stack_a;
	static	t_list *stack_b;
	static	t_list *stack_a_cpy;

	if (c == 'a')
		return (&stack_a);
	if (c == 'b')
		return (&stack_b);
	if (c == 'c')
		return (&stack_a_cpy);
	return (NULL);
}

int	ft_create_stack(char *argc)
{
	int	*nb;
	t_list	**stack;
	t_list	**stack_cpy;

	stack = stack_factory('a');
	stack_cpy = stack_factory('c');
	if (ft_check_if_zero(argc))
	{
		nb = malloc(sizeof(int));
		if (!nb)
			return (0);
		*nb = 0;
		if (*stack == NULL)
		{
			*stack = ft_lstnew(nb);
			*stack_cpy = ft_lstnew(nb);
		}
		else
		{
			ft_lstadd_back(stack, ft_lstnew(nb));
			ft_lstadd_back(stack_cpy, ft_lstnew(nb));
		}
	}
	else
	{
		nb = malloc(sizeof(int));
		if (!nb)
			return (0);
		if (ft_atoi(argc) > INT_MAX || ft_atoi(argc) < INT_MIN)
			return (free(nb), 0);
		*nb = ft_atoi(argc);
		if (*nb == 0)
			return (free(nb), 0);
		if (stack == NULL)
		{
			*stack = ft_lstnew(nb);
			*stack_cpy = ft_lstnew(nb);
		}
		else
		{
			ft_lstadd_back(stack, ft_lstnew(nb));
			ft_lstadd_back(stack_cpy, ft_lstnew(nb));
		}
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
