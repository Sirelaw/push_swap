/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:45:59 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/12 16:19:51 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

int	smallest(int *arr, int size)
{
	int	i;
	int	j;
	int	min;

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

int	smaller(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

int	bigger(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

void	rotate_la_to_min(t_list **la)
{
	int		i;
	t_list	*p;
	int		len;

	i = 0;
	p = *la;
	len = ft_lstsize(*la);
	while (*((int *)(p)->content) != 1)
	{
		p = p->next;
		i++;
	}
	if (i <= (len / 2))
		while (*((int *)(*la)->content) != 1)
			rotate(la, "ra\n");
	else
		while (*((int *)(*la)->content) != 1)
			reverse_rotate(la, "rra\n");
}
