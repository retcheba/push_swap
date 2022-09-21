/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:41:59 by retcheba          #+#    #+#             */
/*   Updated: 2022/09/20 17:20:25 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_parsing_all(t_stack **list_a, t_stack **list_b, char **argv)
{
	*list_a = ft_parsing(*list_a, argv);
	*list_b = ft_parsing(*list_b, argv);
}

static void	ft_choose_algo(t_stack *list_a, t_stack *list_b)
{
	unsigned int	n;

	ft_free_list(list_b);
	list_b = NULL;
	n = len_list(list_a);
	index_list(list_a, n);
	if (!(order_is_correct(list_a, n)) && n > 1)
	{
		if (n == 2)
			list_a = ft_sa(list_a);
		else if (n == 3)
			list_a = algo_for_3(list_a, n);
		else if (n > 3 && n <= 25)
			list_a = algo_diy(list_a, list_b, n);
		else if (n > 25)
			list_a = radix_bin(list_a, list_b, n);
	}
	ft_free_list(list_a);
}

int	main(int argc, char **argv)
{
	t_stack			*list_a;
	t_stack			*list_b;

	if (argc > 1 && !(argv_is_ok(argv)))
	{
		list_a = NULL;
		list_b = NULL;
		ft_parsing_all(&list_a, &list_b, argv);
		if (list_a == NULL || list_b == NULL)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (is_not_duplicates(list_a, list_b))
		{
			ft_free_list(list_a);
			ft_free_list(list_b);
			write(2, "Error\n", 6);
			return (0);
		}
		ft_choose_algo(list_a, list_b);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
