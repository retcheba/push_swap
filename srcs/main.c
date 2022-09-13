/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:41:59 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/13 20:32:29 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_link(t_stack *list, int nb, int index)
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

void	print_list(t_stack *list)
{
	while (list)
	{
		ft_printf("%d  %d\n", list->index, list->nb);
		list = list->next;
	}
}

void	index_list(t_stack	*list, unsigned int n)
{
	t_stack				*begin;
	t_stack				*tmp;
	unsigned int		i = 0;
	int					min = 2147483647;
	int					old_min = -2147483648;

	begin = list;
	while (list)
	{
		if (list->nb == 2147483647)
		{
			list->index = n - 1;
			n--;
		}
		else if (list->nb == -2147483648)
		{
			list->index = 0;
			i++;
		}
		list = list->next;
	}
	while (i < n)
	{
		list = begin;
		min = 2147483647;
		while (list)
		{
			if (list->nb > old_min && list->nb < min
				&& (list->nb != 2147483647 && list->nb !=- 2147483648))
			{
				min = list->nb;
				tmp = list;
			}
			list = list->next;
		}
		old_min = min;
		tmp->index = i;
		i++;
	}
}

int	main(void)
{
	t_stack	*list;
	int		stack[5] = {2147483647, 42, -3, 56, 0};
	int		i = 5;

	list = NULL;
	while (--i >= 0)
		list = add_link(list, stack[i], 0);
	
	ft_printf("Avant indexage:\n");
	print_list(list);

	index_list(list, 5);

	ft_printf("Apres indexage:\n");
	print_list(list);

	return (0);
}
