#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct	s_int
{
	int	content;
	int	*next;	
}t_int;


void	push_a_b(t_list **la, t_list **lb, char *s);
void	swap_sa_sb_ss(t_list **lst, char *s);
void	rotate_ra_rb_rr(t_list **lst, char *s);
void	reverse_rotate_rra_rrb_rrr(t_list **lst, char *s);
int		*get_input(int argc, char **argv);

#endif