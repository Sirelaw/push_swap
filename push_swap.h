#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h>
//# include "push_swap.c"

# define A_HEAD_CONTENT *((int *)(*la)->content)
# define B_HEAD_CONTENT *((int *)(*lb)->content)
# define B_LAST *((int *)(ft_lstlast(*lb))->content)
# define A_LAST *((int *)(ft_lstlast(*la))->content)

void	push(t_list **la, t_list **lb, char *s);
void	swap(t_list **lst, char *s);
void	rotate(t_list **lst, char *s);
void	reverse_rotate(t_list **lst, char *s);
int		*get_input(int argc, char **argv);

t_list	*create_linked_list(int *arr);
void	print_all(void *content);
void print_stacks(t_list *la, t_list *lb, int num);
int	check_sort(t_list *lst, int ret);
void	sort_3(t_list **lst, int num);
void	reverse_sort_3(t_list **lst);
int	*get_index(int *num);
void print_stack(t_list *la);
void	find_largest_push_back(t_list **la, t_list **lb, int len);
void	search_best_move(t_list *la, int part, int moves[2], int index[2]);
void	sort_below_10(t_list **la, t_list **lb,int num);
void	wheel_algo(t_list **la, t_list **lb);

void sort_big(t_list **stack_a, t_list **stack_b);

#endif