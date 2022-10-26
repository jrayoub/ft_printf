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
	int	y;
	int	a;

	y = 7890;
	a = ft_printf("' %s '", "Hello");
	printf("%d", a);
	a = printf("' %s '", "Hello");
	printf("\n%d", a);
	// ft_printf("  calc %d   \n", ft_printf("' %% '"));
	// printf("  calc %d   \n", printf("' %% '"));
}
