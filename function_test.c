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

void	sort_5(t_list **lst, int num)
{
	t_list	*p;
	int		n1;
	int		n2;
	int		n3;
	
	if (num == 4)
	{
		swap_sa_sb_ss(lst, "sa");
		check_sort(lst);
	}
	while (!check_sort(lst, 0))
	{
		p = *lst;
		n1 = *((int *)p->content);
		n2 = *((int *)(p->next)->content);
		n3 = *((int *)((p->next)->next)->content);
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