/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_decide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:25:49 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/10 15:36:55 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	move_stack_rr(t_list **la, t_list **lb, int move_a, int move_b)
{
	rotate_both(la, lb, smaller(move_a, move_b));
	rotate_stack_a(la, move_a - move_b);
	rotate_stack_b(lb, move_b - move_a);
}

static void	move_stack_rrr(t_list **la, t_list **lb, int move_a, int move_b)
{
	int	len_a;
	int	len_b;
	int	temp_a;
	int	temp_b;

	len_a = ft_lstsize(*la);
	len_b = ft_lstsize(*lb);
	move_a = len_a - move_a;
	move_b = len_b - move_b;
	reverse_rotate_both(la, lb, smaller(move_a, move_b));
	temp_a = move_a - smaller(move_a, move_b);
	temp_b = move_b - smaller(move_a, move_b);
	while (temp_a-- > 0)
		reverse_rotate(la, "rra\n");
	while (temp_b-- > 0)
		reverse_rotate(lb, "rrb\n");
}

static void	move_ra_rrb(t_list **la, t_list **lb, int move_a, int move_b)
{
	int	len_b;

	len_b = ft_lstsize(*lb);
	move_b = len_b - move_b;
	rotate_stack_a(la, move_a);
	while (move_b-- > 0)
		reverse_rotate(lb, "rrb\n");
}

static void	move_rra_rb(t_list **la, t_list **lb, int move_a, int move_b)
{
	int	len_a;

	len_a = ft_lstsize(*la);
	move_a = len_a - move_a;
	while (move_a-- > 0)
		reverse_rotate(la, "rra\n");
	rotate_stack_b(lb, move_b);
}

void	move_stacks(t_list **la, t_list **lb, t_list *p, int min_max[2])
{
	int		i;
	int		move_a;
	int		move_b;
	t_list	*temp;

	i = 0;
	move_a = 0;
	move_b = 0;
	temp = *lb;
	while (*((int *)(temp)->content) != *((int *)(p)->content))
	{
		temp = temp->next;
		move_b++;
	}
	move_a = right_insert(*la, min_max, *((int *)(p)->content));
	i = best_rot_type(*la, *lb, move_a, move_b);
	if (i == 0)
		move_stack_rr(la, lb, move_a, move_b);
	if (i == 1)
		move_stack_rrr(la, lb, move_a, move_b);
	if (i == 2)
		move_ra_rrb(la, lb, move_a, move_b);
	if (i == 3)
		move_rra_rb(la, lb, move_a, move_b);
}
