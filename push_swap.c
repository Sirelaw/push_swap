/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:47:14 by oipadeol          #+#    #+#             */
/*   Updated: 2021/12/18 06:13:25 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	int		*num;
	t_list	*la;
	t_list	*lb;

	la = NULL;
	lb = NULL;
	if (argc < 2)
		return (1);
	num = get_input(argc, argv);
	num = get_index(num);
	la = create_linked_list(num);
	if (check_sort(la, 0))
		free_stack_array_exit(&la, &lb, &num, 1);
	if (num[0] <= 3)
		sort_3(&la, num[0]);
	else if (num[0] <= 10)
		sort_below_10(&la, &lb, num[0]);
	else
		cost_algo(&la, &lb, find_lis(num, num[0]));
	free_stack_array_exit(&la, &lb, &num, 0);
	return (0);
}
