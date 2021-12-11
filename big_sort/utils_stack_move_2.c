/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_move_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:56:09 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/11 16:07:39 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*create_linked_list(int *arr)
{
	int		i;
	t_list	*lst;

	i = arr[0];
	lst = ft_lstnew((int *) &arr[i]);
	while (--i > 0)
		ft_lstadd_front(&lst, ft_lstnew((int *) &arr[i]));
	return (lst);
}

int	find_fit(t_list *lst, int index)
{
	t_list	*p;
	int		i;

	i = 0;
	p = lst;
	if (((*((int *)(p)->content)) > index)
			&& (((*((int *)(ft_lstlast(p))->content)) < index)))
		return (0);
	else
	{
		i++;
		while (!(((*((int *)(p)->content)) < index)
			&& (((*((int *)(p->next)->content)) > index))))
		{
			p = p->next;
			i++;
		}
	}
	return (i);
}

int	right_insert(t_list *lst, int min_max[2], int index)
{
	t_list	*p;
	int		i;

	i = 0;
	p = lst;
	if ((index < min_max[0]) || (index > min_max[1]))
	{
		while ((*((int *)(p)->content)) != min_max[0])
		{
			i++;
			p = p->next;
		}
	}
	else
		i = find_fit(lst, index);
	return (i);
}

int	best_rot(t_list *la, t_list *lb, int move_a, int move_b)
{
	int	pos[4];
	int	len_a;
	int	len_b;
	int	temp;

	len_a = ft_lstsize(la);
	len_b = ft_lstsize(lb);
	pos[0] = bigger(move_a, move_b);
	pos[1] = bigger((len_a - move_a), (len_b - move_b));
	pos[2] = move_a + (len_b - move_b);
	pos[3] = move_b + (len_a - move_a);
	temp = smallest(pos, 4);
	return (pos[temp]);
}

int	best_rot_type(t_list *la, t_list *lb, int move_a, int move_b)
{
	int	pos[4];
	int	len_a;
	int	len_b;
	int	temp;

	len_a = ft_lstsize(la);
	len_b = ft_lstsize(lb);
	pos[0] = bigger(move_a, move_b);
	pos[1] = bigger((len_a - move_a), (len_b - move_b));
	pos[2] = move_a + (len_b - move_b);
	pos[3] = move_b + (len_a - move_a);
	temp = smallest(pos, 4);
	return (temp);
}
