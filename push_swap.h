#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h>
//# include "push_swap.c"

void	push(t_list **la, t_list **lb, char *s);
void	swap(t_list **lst, char *s);
void	rotate(t_list **lst, char *s);
void	reverse_rotate(t_list **lst, char *s);
int		*get_input(int argc, char **argv);

t_list	*create_linked_list(int *arr);
void	print_all(void *content);
void print_stacks(t_list *la, t_list *lb, int num);
int	check_sort(t_list *lst, int ret);
void	sort_3(t_list **lst, int num, int ret);
int	*get_index(int *num);
void print_stack(t_list *la);
void	find_largest_push_back(t_list **la, t_list **lb, int len);

#endif