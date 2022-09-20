/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:03:40 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/18 22:51:27 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_link(int nb, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->nb = nb;
		new->index = index;
		new->next = NULL;
	}
	return (new);
}

t_stack	*add_link_bottom(t_stack *list, t_stack *new)
{
	t_stack *begin;

	begin = list;
	while (list->next)
		list = list->next;
	list->next = new;
	return (begin);
}

t_stack	*add_link_top(t_stack *list, int nb, int index)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (tmp)
	{
		tmp->nb = nb;
		tmp->index = index;
		tmp->next = list;
	}
	return (tmp);
}

int	len_list(t_stack *list)
{
	int	i = 1;

	while (list)
	{
		i++;
		list = list->next;
	}
	return (i - 1);
}

void	ft_free_list(t_stack *list)
{
	t_stack *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
		tmp = NULL;
	}
}
