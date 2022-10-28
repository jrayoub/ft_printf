/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:26:23 by aaitouna          #+#    #+#             */
/*   Updated: 2022/10/17 02:04:27 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/ft_printf.h"

int	main(int ac, char **av)
{
	int	a;
	int	b;

	ft_printf("#Test 1 \n");
	a = ft_printf("%p", LONG_MIN);
	ft_printf("\n\torgin \n\t");
	b = printf("%p", (void *)LONG_MIN);
	printf("\na = %d b = %d \n", a, b);
	ft_printf("#Test 2 \n");
	a = ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	b = printf(" %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("\na = %d b = %d \n", a, b);
	ft_printf("#Test 3 \n");
	a = ft_printf(" %p %p ", 0, 0);
	b = printf(" %p %p ", (void *)0, (void *)0);
	printf("\na = %d b = %d \n", a, b);
}
