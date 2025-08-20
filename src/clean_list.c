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

static int	clean_lst_swp(t_params *params)
{
	params->done = 0;
	params->aux = (params->next)->next;
	ft_lstdelone(params->head, free);
	ft_lstdelone(params->next, free);
	if (params->prev == NULL)
	{
		(*(stack_factory('m'))) = params->aux;
		params->head = *(stack_factory('m'));
		params->next = (*(stack_factory('m')))->next;
	}
	else
	{
		(params->prev)->next = params->aux;
		if (!(params->prev)->next)
			return (1);
		params->head = (params->prev)->next;
		params->next = (params->head)->next;
	}
	return (0);
}

static int	clean_lst_next(t_params *params)
{
	params->prev = params->head;
	params->head = params->next;
	if (!params->next)
		return (1);
	params->next = (params->next)->next;
	return (0);
}

void	clean_list(t_params params)
{
	params.done = 0;
	while (!params.done)
	{
		params.done = 1;
		params.prev = NULL;
		params.head = *(stack_factory('m'));
		if (!params.head)
			break ;
		params.next = (*(stack_factory('m')))->next;
		while (params.next)
		{
			if (!ft_strncmp((const char *) params.head
					->content, (const char *)params
					.mv_1, ft_strlen(params.mv_1)))
			{
				if (!ft_strncmp((const char *) params.next
						->content, (const char *)params
						.mv_2, ft_strlen(params.mv_2)))
					if (clean_lst_swp(&params))
						break ;
			}
			if (clean_lst_next(&params))
				break ;
		}
	}
}
