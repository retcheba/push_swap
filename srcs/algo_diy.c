/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_diy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:32:27 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/22 01:06:04 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	i_in_top_of_stack(t_stack *list, unsigned int index, unsigned int n)
{
	t_stack			*begin;
	unsigned int	i;

	i = 0;
	begin = list;
	while (i < n / 2)
	{
		if (list->index == index)
		{
			list = begin;
			return (1);
		}
		list = list->next;
		i++;
	}
	list = begin;
	return (0);
}

static void	algo_diy_part2(t_stack **list_a, t_stack **list_b, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (++i < n - 2)
	{
		ft_printf("pa\n");
		*list_a = add_link_top(*list_a, (*list_b)->nb, (*list_b)->index);
		*list_b = ft_next(*list_b);
	}
	*list_b = NULL;
}

t_stack	*algo_diy(t_stack *list_a, t_stack *list_b, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (++i < n - 2)
	{
		while (list_a->index != i)
		{
			if (i_in_top_of_stack(list_a, i, n))
				list_a = ft_ra(list_a);
			else
				list_a = ft_rra(list_a);
		}
		ft_printf("pb\n");
		list_b = add_link_top(list_b, list_a->nb, list_a->index);
		list_a = ft_next(list_a);
	}
	list_a = algo_for_3(list_a, n);
	algo_diy_part2(&list_a, &list_b, n);
	return (list_a);
}
