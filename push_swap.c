/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:47:14 by oipadeol          #+#    #+#             */
/*   Updated: 2021/11/21 02:39:39 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_sort(t_list *lst)
{
	t_list	*p;
	int		num1;
	int		num2;
	
	p = lst;
	while (p->next != NULL)
	{
		num1 = *((int *)(p->content));
		num2 = *((int *)((p->next)->content));
		if (num1 > num2)
			break;
		p = p->next;
	}
	if (p->next == NULL)
		exit(EXIT_SUCCESS);
}

void	print_all(void *content)
{
	ft_putnbr_fd(*((int *) content), STDIN_FILENO);
	ft_putstr_fd(" ", STDIN_FILENO);
}

int	*get_index(int *num)
{
	int i;
	int	j;
	int	smaller;
	int	*indexx;

	indexx = ft_calloc(num[0] + 1, sizeof(int));
	i = 0;
	j = 1;
	smaller = 1;
	indexx[0] = num[0];
	while (i++ < num[0])
	{
		j = 0;
		while (j++ < num[0])
		{
			if (num[j] < num[i])
				smaller++;
		}
		indexx[i] = smaller;
		smaller = 1;
	}
	free(num);
	return (indexx);
}
void	sort_3(t_list **lst, int num)
{
	t_list	*p;
	int		i;
	
	p = *lst;
	i = p->content;
	if (num == 2)
		swap_sa_sb_ss(lst, "sa");
		
}

int	main(int argc, char **argv)
{
	int		*num;
	int		i;
	t_list	*la;
	t_list	*lb;

	i = 0;
	if (argc < 2)
		return (1);
	num = get_input(argc, argv);
	num = get_index(num);
	
	la = create_linked_list(num);
	check_sort(la);
	ft_lstiter(la, print_all);
	if (num[0] <= 3)
		sort_3(&la, num[0]);
	// else if (num[0] <= 5)
	// 	sort_5(&la, num[0]);
	// else if (num[0] <= 7)
	// 	sort_7(&la, num[0]);
	// else
	// 	sort_5(&la, num[0]);
	ft_lstiter(la, print_all);
	ft_putchar_fd('\n', 1);
	ft_lstiter(lb, print_all);
	ft_putchar_fd('\n', 1);
	ft_lstiter(la, print_all);
	free(num);
	return (0);
}

