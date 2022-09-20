/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:23:50 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/20 05:30:04 by retcheba         ###   ########.fr       */
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

int		is_only_numbers(char *str);
int	is_an_int(char **stack);
int		ft_cmpt_word(char **stack);
void 	ft_free_stack(char **stack);
char	*ft_merge(char **argv);
t_stack	*ft_parsing(t_stack *list_a, char **argv);
int		bin_len(unsigned int n);
t_stack	*ft_next(t_stack *list_a);
t_stack	*ft_ra(t_stack *list);
t_stack	*ft_sa(t_stack *list);
t_stack	*radix_bin(t_stack *list_a, t_stack *list_b, int n);
void	index_list(t_stack	*list, unsigned int n);
t_stack	*add_link_top(t_stack *list, int nb, int index);
t_stack	*add_link_bottom(t_stack *list, t_stack *new);
int		len_list(t_stack *list);
t_stack	*new_link(int nb, int index);
void	ft_free_list(t_stack *list);
t_stack *algo_DIY(t_stack *list_a, t_stack *list_b, unsigned int n);
t_stack *algo_for_3(t_stack *list, unsigned int n);
int	order_is_correct(t_stack *list, int n);
int	is_not_duplicates(t_stack *list_a, t_stack *list_b);

#endif
