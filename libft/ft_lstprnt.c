/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:26:55 by pedde-so          #+#    #+#             */
/*   Updated: 2025/06/08 13:26:56 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprnt(t_list *lst)
{
	int	i;

	write(1, "[", 1);
	while (lst)
	{
		i = *((int *) lst->content);
		ft_putnbr_fd(i, 1);
		if (lst->next)
			write(1, ", ", 2);
		lst = lst->next;
	}
	write(1, "]", 1);
}
