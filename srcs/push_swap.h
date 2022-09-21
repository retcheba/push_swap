/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:23:50 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/22 00:52:49 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack	t_stack;

struct s_stack
{
	int				nb;
	unsigned int	index;
	t_stack			*next;
};

t_stack	*ft_parsing(t_stack *list_a, char **argv);
void	index_list(t_stack	*list, unsigned int n);
t_stack	*radix_bin(t_stack *list_a, t_stack *list_b, int n);
t_stack	*algo_diy(t_stack *list_a, t_stack *list_b, unsigned int n);
t_stack	*algo_for_3(t_stack *list, unsigned int n);
int		argv_is_ok(char **argv);
int		is_only_numbers(char *str);
int		is_an_int(char **stack);
int		order_is_correct(t_stack *list, int n);
int		is_not_duplicates(t_stack *list_a, t_stack *list_b);
t_stack	*ft_next(t_stack *list_a);
t_stack	*ft_rra(t_stack *list);
t_stack	*ft_ra(t_stack *list);
t_stack	*ft_sa(t_stack *list);
t_stack	*new_link(int nb, int index);
t_stack	*add_link_bottom(t_stack *list, t_stack *new);
t_stack	*add_link_top(t_stack *list, int nb, int index);
int		len_list(t_stack *list);
void	ft_free_list(t_stack *list);

#endif
