#include "push_swap.h"

void	quick_sort(t_list **la, t_list **lb, int len, int prev_pivot)
{
	int	pivot;
	int pushes;
	
	pivot = len / 2;
	while (pushes < pivot - prev_pivot)
	{
		if (*((int *)(*la)->content) > pivot)
			rotate(la, "ra\n");
		else
			push(la, lb, "pb\n");
	}
	if (!check_sort(*la, 0))
		quick_sort(la, lb, len / 2, pivot);
	else
		print_stacks(*la, *lb, len + 2);
}