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

#include "./ft_printf.h"

static int	calc_number_len(int num)
{
	int	i;

	i = 0;
	if (num < 0)
		i++;
	i += Calc_size(num, 10);
	return (i);
}

int	print_and_calc_num(int num)
{
	int	printed_index;

	printed_index = calc_number_len(num);
	ft_putnbr_fd(num, 1);
	return (printed_index);
}

int	print_and_calc_str(char *str)
{
	int	printed_index;

	printed_index = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (printed_index);
}

int	printer(va_list ap, const char *str)
{
	int	i;
	int	printed_index;

	printed_index = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c' && str[i++])
		{
			ft_putchar_fd(va_arg(ap, int), 1);
			printed_index++;
		}
		else if (str[i] == '%' && str[i + 1] == 's' && str[i++])
			printed_index += print_and_calc_str(va_arg(ap, char *));
		else if (str[i] == '%' && str[i + 1] == 'p' && str[i++])
			print_ptr_adress(va_arg(ap, long), &printed_index);
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i')
				&& str[i++])
			printed_index += print_and_calc_num(va_arg(ap, int));
		else if (str[i] == '%' && str[i + 1] == 'u' && str[i++])
			ft_put_unsigned(va_arg(ap, unsigned int), &printed_index);
		else if (str[i] == '%' && (str[i + 1] == 'x' || str[i + 1] == 'X')
				&& str[i++])
			print_hex(va_arg(ap, int), str[i], &printed_index);
		else if (str[i] == '%' && str[i + 1] != '%' && str[i++])
			return (0);
		else
		{
			ft_putchar_fd(str[i], 1);
			printed_index++;
		}
		i++;
	}
	return (printed_index);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printed_index;

	va_start(ap, str);
	printed_index = printer(ap, str);
	va_end(ap);
	return (printed_index);
}
