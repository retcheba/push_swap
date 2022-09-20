/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:52:07 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/20 00:28:38 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*radix_bin(t_stack *list_a, t_stack *list_b, int n)
{
	int	lbm = 0;
	int	i = 0;
	int	j = 0;
	int	cmp = 0;

	lbm = bin_len(n);
	list_b = NULL;
	while (i < lbm)
	{
		j = 0;
		while (j < n)
		{
			if (list_a->index >> i & 1)
				list_a = ft_ra(list_a);
			else
			{
				ft_printf("pb\n");
				cmp++;
				list_b = add_link_top(list_b, list_a->nb, list_a->index);
				list_a = ft_next(list_a);
			}
			j++;
		}
		j = 0;
		while(j < cmp)
		{
			ft_printf("pa\n");
			list_a = add_link_top(list_a, list_b->nb, list_b->index);
			list_b = ft_next(list_b);
			j++;
		}
		list_b = NULL;
		cmp = 0;
		i++;
	}
	return (list_a);
}
