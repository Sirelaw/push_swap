#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

void	push(t_list **la, t_list **lb, char *s);
void	swap(t_list **lst, char *s);
void	rotate(t_list **lst, char *s);
void	reverse_rotate(t_list **lst, char *s);
int		*get_input(int argc, char **argv);

#endif