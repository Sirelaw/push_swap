/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:47:14 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/10 15:31:38 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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

int	main(int argc, char **argv)
{
	int		*num;
	int		i;
	t_list	*la;
	t_list	*lb;

	lb = NULL;
	la = NULL;
	i = 0;
	if (argc < 2)
		return (1);
	num = get_input(argc, argv);
	num = get_index(num);
	la = create_linked_list(num);
	if (check_sort(la, 1))
		free_stack_array_exit(&la, &lb, &num, 1);
	if (num[0] <= 3)
		sort_3(&la, num[0]);
	else if (num[0] <= 10)
		sort_below_10(&la, &lb, num[0]);
	else
		cost_algo(&la, &lb, find_lis(num, num[0]));
	if (check_sort(la, 0))
		ft_putstr_fd("Sorted\n", 2);
	free_stack_array_exit(&la, &lb, &num, 0);
	return (0);
}
