/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:10:57 by pedde-so          #+#    #+#             */
/*   Updated: 2025/08/16 14:10:58 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_LIST_H
# define CLEAN_LIST_H

#include "libft.h"
#include <unistd.h>
#include <limits.h>

typedef struct s_params
{
	int	done;
	t_list	*prev;
	t_list	*head;
	t_list	*next;
	t_list	*aux;
	char	*mv_1;
	char	*mv_2;
}	t_params;

void	clean_list(t_params params);
void	clean_list_all_moves(void);

#endif
