/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:43:03 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/07 00:09:39 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int biggest(int *arr, int size)// OK
{
	int i;
	int max;

	max = 0;
	i = 0;
	while (i < size)
	{
		if (max < arr[i])
			max = arr[i];
		i++;
	}
	return (max);
}

int smallest(int *arr, int size)//Ok
{
	int i;
	int	j;
	int min;
	
	min = arr[0];
	i = 0;
	j = 0;
	while (i < size)
	{
		if (min > arr[i])
		{
			min = arr[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void	rotate_both(t_list **la, t_list **lb, int n)//OK
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

int bigger(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

int smaller(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}


void	move_stack_a(t_list **la, int move)
{
	int len;

	len = ft_lstsize(*la);
	if (move <= 0)
		move = 0;
	if (move <= ((len / 2) + 1))
	{
		while(move-- > 0)
			rotate(la, "ra\n");
	}
	else
	{
		move = len - move;
		while (move-- > 0)
			reverse_rotate(la, "rra\n");
	}
}

int direction_check(t_list *lst, int move)
{
	int len;

	len = ft_lstsize(lst);
	if (move <= 0)
		move = 0;
	if (move <= ((len / 2) + 1))
		return (1);
	else
		return (2);
}

void	move_stack_b(t_list **lb, int move)
{
	int len;

	len = ft_lstsize(*lb);
	if (move < 0)
		move = 0;
	if (move <= ((len / 2) + 1))
	{
		while(move-- > 0)
			rotate(lb, "rb\n");
	}
	else
	{
		move = len - move;
		while (move-- > 0) 
			reverse_rotate(lb, "rrb\n");
	}

}

int find_fit(t_list *lb, int index)
{
	t_list	*p;
	int		i;

	i = 0;
	p = lb;
	if (((*((int *)(p)->content)) < index) 
			&& (((*((int *)(ft_lstlast(p))->content)) > index)))
		return (0);
	else
	{
		i++;
		while (!(((*((int *)(p)->content)) > index) 
			&& (((*((int *)(p->next)->content)) < index))))
		{
			p = p->next;
			i++;
		}
	}
	return (i);
}

int	right_insert(t_list *lb, int min_max[2], int index)
{
	t_list	*p;
	int i;

	i = 0;
	p = lb;
	if ((index < min_max[0]) || (index > min_max[1]))
	{
		while ((*((int *)(p)->content)) != min_max[1])
		{
			i++;
			p = p->next;
		}
	}
	else
		i = find_fit(lb, index);
	return (i);
}

int	*get_insert_cost(t_list *la, t_list *lb, int min_max[2], int *temp)
{
	t_list *p;
	int i;
	int len_b;

	p = la;
	i = 0;
	len_b = ft_lstsize(lb);
	while (p != NULL)
	{
		temp[i] = right_insert(lb, min_max, *((int *)(p)->content));
		i++;
		p = p->next;
	}
	i = 0;
	while (i++ < len_b)
	{
		if (temp[i - 1] > ((len_b / 2) + 1))
			temp[i - 1] = len_b - temp[i - 1];
	}
	return (temp);
}

int magic_algo(t_list *la, t_list *lb, int min_max[2])
{
	int len_a;
	int len_b;
	int i;
	int *temp;
	int *tot_moves;


	temp = NULL;
	tot_moves = NULL;
	len_a = ft_lstsize(la);
	len_b = ft_lstsize(lb);
	i = 0;
	tot_moves = malloc(len_a * sizeof(int));
	temp = malloc(len_a * sizeof(int));
	while (i++ < len_a)
		tot_moves[i - 1] = i - 1;
	i = 0;
	while (i++ < len_a)
	{
		if (tot_moves[i - 1] > ((len_a / 2) + 1))
			tot_moves[i - 1] = len_a - tot_moves[i - 1];
	}
	temp = get_insert_cost(la, lb, min_max, temp);
	i = 0;
	while (i++ < len_a)
		tot_moves[i - 1] += temp[i - 1];
	i = smallest(tot_moves, len_a);
	// free(temp);
	// free(tot_moves);
	return (i);
}

void	move_both(t_list **la, t_list **lb, int move_a, int move_b)
{
	int direction_a;
	int direction_b;

	direction_a = direction_check(*la, move_a);
	direction_b = direction_check(*lb, move_b);
	if ((direction_a == direction_b) && (direction_b == 1))
	{
		if (direction_a == 1)
		{
			rotate_both(la, lb, smaller(move_a, move_b));
			move_stack_a(la, move_a - move_b);
			move_stack_b(lb, move_b - move_a);
		}
		else
		{
			reverse_rotate_both(la, lb, smaller(move_a, move_b));
			move_a = move_a - smaller(move_a, move_b);
			move_b = move_b - smaller(move_a, move_b);
			while (--move_a > 0)
				reverse_rotate(la, "rra\n");
			while (--move_b > 0)
				reverse_rotate(lb, "rrb\n");
		}
	}
	else
	{
		move_stack_a(la, move_a);
		move_stack_b(lb, move_b);
	}
}

void	move_stacks(t_list **la, t_list **lb, t_list *p, int min_max[2])
{
	int i;
	int j;
	int move_a;
	int move_b;
	t_list	*temp;

	i = 0;
	j = 0;
	move_a = 0;
	move_b = 0;
	temp = *la;
	while (*((int *)(temp)->content) != *((int *)(p)->content))
	{
		temp = temp->next;
		move_a++;
	}
	move_b = right_insert(*lb, min_max, *((int *)(p)->content));
	move_both(la, lb, move_a, move_b);
	// move_stack_a(la, move_a);
	// move_stack_b(lb, move_b);
}

void	rotate_to_min(t_list **la)
{
	int i;
	t_list *p;
	
	i = 0;
	p = *la;
	while (*((int *)(p)->content) != 1)
	{
		p = p->next;
		i++;
	}
	move_stack_a(la, i);
}

void	wheel_algo(t_list **la, t_list **lb)
{
	int i;
	int min_max[2];
	int	moves[2];
	t_list *p;

	i = 0;
	while (i++ < 3)
		push(la, lb, "pb\n");
	reverse_sort_3(lb);
	min_max[0] = *((int *)(ft_lstlast(*lb))->content);
	min_max[1] = *((int *)(*lb)->content);
	while(*la)
	{
		p = ft_lstelem(*la, magic_algo(*la, *lb, min_max));
		move_stacks(la, lb, p, min_max);
		push(la, lb, "pb\n");
		if (*((int *)(*lb)->content) > min_max[1])
			min_max[1] = *((int *)(*lb)->content);
		if (*((int *)(*lb)->content) < min_max[0])
			min_max[0] = *((int *)(*lb)->content);
	}
	while (*lb)
		push(lb, la, "pa\n");
	rotate_to_min(la);
}
