/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:43:57 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/11 17:31:32 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_both(t_list **la, t_list **lb, int n)
{
	while (n-- > 0)
	{		
		rotate(la, "");
		rotate(lb, "rr\n");
	}
}

void	reverse_rotate_both(t_list **la, t_list **lb, int n)
{
	while (n-- > 0)
	{
		reverse_rotate(la, "");
		reverse_rotate(lb, "rrr\n");
	}
}

void	rotate_stack_a(t_list **la, int move)
{
	if (move <= 0)
		move = 0;
	while (move-- > 0)
		rotate(la, "ra\n");
}

void	rotate_stack_b(t_list **lb, int move)
{
	if (move < 0)
		move = 0;
	while (move-- > 0)
		rotate(lb, "rb\n");
}
