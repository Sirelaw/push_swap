/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:09:58 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/11 16:10:56 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack_array_exit(t_list **la, t_list **lb, int **num, int exit_st)
{
	int		i;
	t_list	*p;
	t_list	*temp;

	i = 0;
	while (i++ < 2)
	{
		if (i - 1 == 0)
			p = *la;
		else if (i - 1 == 1)
			p = *lb;
		while (p != NULL)
		{
			temp = p->next;
			free(p);
			p = temp;
		}
	}
	free(*num);
	if (exit_st)
		exit(exit_st);
}
