/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:44:03 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/22 00:52:16 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_next(t_stack *list_a)
{
	t_stack	*tmp;

	tmp = list_a;
	list_a = list_a->next;
	free(tmp);
	tmp = NULL;
	return (list_a);
}

static t_stack	*ft_raf(t_stack *list)
{
	t_stack	*new;

	new = new_link(list->nb, list->index);
	list = ft_next(list);
	list = add_link_bottom(list, new);
	return (list);
}

t_stack	*ft_rra(t_stack *list)
{
	int	i;
	int	len;

	i = 0;
	len = len_list(list);
	while (i < len - 1)
	{
		list = ft_raf(list);
		i++;
	}
	ft_printf("rra\n");
	return (list);
}

t_stack	*ft_ra(t_stack *list)
{
	t_stack	*new;

	new = new_link(list->nb, list->index);
	list = ft_next(list);
	list = add_link_bottom(list, new);
	ft_printf("ra\n");
	return (list);
}

t_stack	*ft_sa(t_stack *list)
{
	int				nb;
	unsigned int	index;

	nb = list->nb;
	index = list->index;
	list->nb = list->next->nb;
	list->index = list->next->index;
	list->next->nb = nb;
	list->next->index = index;
	ft_printf("sa\n");
	return (list);
}
