/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:52:07 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/21 15:59:16 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_bitwise(t_stack **list_a, t_stack **list_b, int n, int i)
{
	int	j;
	int	cmp;

	j = -1;
	cmp = 0;
	while (++j < n)
	{
		if ((*list_a)->index >> i & 1)
			*list_a = ft_ra(*list_a);
		else
		{
			ft_printf("pb\n");
			cmp++;
			*list_b = add_link_top(*list_b, (*list_a)->nb, (*list_a)->index);
			*list_a = ft_next(*list_a);
		}
	}
	j = -1;
	while (++j < cmp)
	{
		ft_printf("pa\n");
		*list_a = add_link_top(*list_a, (*list_b)->nb, (*list_b)->index);
		*list_b = ft_next(*list_b);
	}
}

t_stack	*radix_bin(t_stack *list_a, t_stack *list_b, int n)
{
	int	lbm;
	int	i;

	lbm = bin_len(n);
	i = 0;
	while (i < lbm)
	{
		list_b = NULL;
		radix_bitwise(&list_a, &list_b, n, i);
		i++;
	}
	return (list_a);
}
