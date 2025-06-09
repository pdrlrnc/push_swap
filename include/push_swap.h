/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:40:30 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/28 15:40:31 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int	ft_start_stack(t_list *stack, char *argc);
int	ft_isspace(char c);
int	ft_check_if_zero(char *str);
t_list	**stack_factory(char c);
int	ft_create_stack(t_list **stack, char *argc);
int	swap_a();
int	swap_b();
int	ss();
int	push_a();
int	push_b();
int	rotate_a();
int	rotate_b();
int	rr();

#endif
