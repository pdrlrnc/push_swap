/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:01:39 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/24 12:01:40 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	clean_list_reverse(void)
{
	int	done;
	t_list	*prev;
	t_list	*head;
	t_list	*next;
	t_list	*aux;
	char	*ra;
	char	*rra;

	ra = "ra\n";
	rra = "rra\n";
	done = 0;
	while (!done)
	{
		done = 1;
		prev = NULL;
		head = *(stack_factory('m'));
		if (!head)
			break;
		next = (*(stack_factory('m')))->next;
		while (next)
		{
			if (!ft_strncmp((const char *) head->content, (const char *)rra, 2))
			{
				if (!ft_strncmp((const char *) next->content, (const char *)ra, 3))
				{
					done = 0;
					aux = next->next;
					ft_lstdelone(head, free);
					ft_lstdelone(next, free);
					if (prev == NULL)
					{
						(*(stack_factory('m'))) = aux;
						head = *(stack_factory('m'));
						next = (*(stack_factory('m')))->next;
					}
					else
					{
						prev->next = aux;
						if (!prev->next)
							break;
						head = prev->next;
						next = head->next;
					}

				}
			}
				prev = head;
				head = next;
				if (!next)
					break;
				next = next->next;
		}
	}
}

void	clean_list(void)
{
	int	done;
	t_list	*prev;
	t_list	*head;
	t_list	*next;
	t_list	*aux;
	char	*ra;
	char	*rra;

	ra = "ra\n";
	rra = "rra\n";
	done = 0;
	while (!done)
	{
		done = 1;
		prev = NULL;
		head = *(stack_factory('m'));
		if (!head)
			break;
		next = (*(stack_factory('m')))->next;
		while (next)
		{
			if (!ft_strncmp((const char *) head->content, (const char *)ra, 2))
			{
				if (!ft_strncmp((const char *) next->content, (const char *)rra, 3))
				{
					done = 0;
					aux = next->next;
					ft_lstdelone(head, free);
					ft_lstdelone(next, free);
					if (prev == NULL)
					{
						(*(stack_factory('m'))) = aux;
						head = *(stack_factory('m'));
						next = (*(stack_factory('m')))->next;
					}
					else
					{
						prev->next = aux;
						if (!prev->next)
							break;
						head = prev->next;
						next = head->next;
					}

				}
			}
				prev = head;
				head = next;
				if (!next)
					break;
				next = next->next;
		}
	}
	clean_list_reverse();
}

