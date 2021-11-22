#include "push_swap.h"





void	sort_3(t_list **lst, int num, int ret)
{
	t_list	*p;
	int		n1;
	int		n2;
	int		n3;
	
	p = *lst;
	n1 = *((int *)p->content);
	n2 = *((int *)(p->next)->content);
	n3 = *((int *)((p->next)->next)->content);
	if (num == 2)
		swap_sa_sb_ss(lst, "sa");
	else
	{
		if ((n1 < n3) && (n2 > n3))//OK 1 3 2
		{
			reverse_rotate_rra_rrb_rrr(lst, "rra");
			swap_sa_sb_ss(lst, "sa");
		}
		// ft_putnbr_fd(n1, 1);
		// ft_putchar_fd('\n', 1);
		if ((n1 > n2) && (n1 < n3))//OK 2 1 3
			swap_sa_sb_ss(lst, "sa");
		if ((n1 > n3) && (n2 > n1))//OK 2 3 1
			reverse_rotate_rra_rrb_rrr(lst, "rra");
		if ((n1 > n2) && (n2 > n3))//OK 3 2 1
		{
			swap_sa_sb_ss(lst, "sa");
			reverse_rotate_rra_rrb_rrr(lst, "rra");
		}
		if ((n1 > n3) && (n3 > n2))//OK 3 1 2
		{
			reverse_rotate_rra_rrb_rrr(lst, "rra");
			reverse_rotate_rra_rrb_rrr(lst, "rra");
		}
	}
		
}

void	sort_5(t_list **la, int num)
{
	t_list	*p;
	t_list	*lb;
	int		n1;
	int		move_count;
	
	n1 = 1;
	while ((check_sort(*la, 0)) || (n1 <= num - 3))
	{
		move_count = 0;
		p = *la;
		while (*((int *)p->content) != n1)
		{
			p = p->next;
			move_count++;
		}
		if (move_count <= num/2)
		{
			while (*((int *)(*la)->content) != n1)
				rotate(la, "ra\n");
		}
		else
		{
			while (*((int *)(*la)->content) != n1)
				reverse_rotate(la, "rra\n");
		}
		push(la, &lb, "pb\n");
		n1++;
	}
	sort_3(la, 3, 0);
	while (lb != NULL)
		push(&lb, la, "pa\n");
	check_sort(*la, 1);
}

void	sort_5(t_list **la, t_list **lb,int num)
{
	t_list	*p;
	int		n1;
	int		stack_size;
	int		move_f1_count;
	int		move_b1_count;
	
	n1 = 1;
	stack_size = num;
	while (stack_size > 3)
	{
		if (check_sort(*la, 0))
			break;
		move_f1_count = 0;
		move_b1_count = 0;
		p = *la;
		while (*((int *)p->content) != n1)
		{
			p = p->next;
			move_f1_count++;
		}
		while (*((int *)p->content) != num)
		{
			p = p->next;
			move_b1_count++;
		}
		if (move_f1_count < move_f1_count)
		if (move_f1_count <= stack_size/2)
		{
			while (*((int *)(*la)->content) != n1)
				rotate(la, "ra\n");
		}
		else
		{
			while (*((int *)(*la)->content) != n1)
				reverse_rotate(la, "rra\n");
		}
		if (check_sort(*la, 0))
			break;
		push(la, lb, "pb\n");
		n1++;
		stack_size--;
	}
	if (stack_size == 3)
		sort_3(la, 3, 0);
	while ((*lb) != NULL)
		push(lb, la, "pa\n");
	ft_lstiter(*la, print_all);
	ft_putchar_fd('\n', 1);
	check_sort(*la, 1);
}