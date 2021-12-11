/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:43:03 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/11 20:50:04 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	get_insert_cost(t_list *la, t_list *lb, int min_max[2], int **temp)
{
	t_list	*p;
	int		i;
	int		len_a;

	p = lb;
	i = 0;
	len_a = ft_lstsize(la);
	while (p != NULL)
	{
		(*temp)[i] = right_insert(la, min_max, *((int *)(p)->content));
		i++;
		p = p->next;
	}
}

static void	get_total_moves(t_list *la, t_list *lb, int **tot_mov, int *temp)
{
	int	i;
	int	len_b;

	len_b = ft_lstsize(lb);
	i = 0;
	while (i++ < len_b)
		(*tot_mov)[i - 1] = i - 1;
	i = 0;
	while (i++ < len_b)
		(*tot_mov)[i - 1] = best_rot(la, lb, temp[i - 1], (*tot_mov)[i - 1]);
}

static int	magic_algo(t_list *la, t_list *lb, int min_max[2])
{
	int	len_b;
	int	i;
	int	*temp;
	int	*a_moves;

	len_b = ft_lstsize(lb);
	i = 0;
	a_moves = (int *) malloc(len_b * sizeof(int));
	if (a_moves == NULL)
		return (0);
	temp = (int *) malloc(len_b * sizeof(int));
	if (temp == NULL)
		return (0);
	get_insert_cost(la, lb, min_max, &temp);
	get_total_moves(la, lb, &a_moves, temp);
	i = smallest(a_moves, len_b);
	free(temp);
	free(a_moves);
	return (i);
}

static void	push_non_lis_to_b(t_list **la, t_list **lb, int *lis)
{
	int	i;

	i = 1;
	while (*((int *)(*la)->content) != lis[0])
		push(la, lb, "pb\n");
	rotate(la, "ra\n");
	while (*((int *)(*la)->content) != lis[0])
	{
		if (*((int *)(*la)->content) == lis[i])
		{
			i++;
			rotate(la, "ra\n");
		}
		else
			push(la, lb, "pb\n");
	}
}

void	cost_algo(t_list **la, t_list **lb, int *lis)
{
	int		min_max[2];
	t_list	*p;

	push_non_lis_to_b(la, lb, lis);
	min_max[1] = *((int *)(ft_lstlast(*la))->content);
	min_max[0] = *((int *)(*la)->content);
	while (*lb)
	{
		p = ft_lstelem(*lb, magic_algo(*la, *lb, min_max));
		move_stacks(la, lb, p, min_max);
		push(lb, la, "pa\n");
		if (*((int *)(*la)->content) > min_max[1])
			min_max[1] = *((int *)(*la)->content);
		if (*((int *)(*la)->content) < min_max[0])
			min_max[0] = *((int *)(*la)->content);
	}
	rotate_la_to_min(la);
	free(lis);
}
