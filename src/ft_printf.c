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

static void	ft_putunsigned(unsigned int num)
{
	char	c;

	if (num >= 10)
		ft_putunsigned(num / 10);
	c = '0' + num % 10;
	write(1, &c, 1);
}

// x && X
void	Converter(char *s, unsigned long int n, int index, char format)
{
	if (n == 0)
		s[0] = '0';
	index -= 1;
	if (n >= 16)
		Converter(s, n / 16, index, format);
	s[index] = (n % 16 < 10 ? 48 : (format == 120 ? 87 : 55)) + (n % 16);
}

int	Calc_size(unsigned long int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	print_hex(unsigned long int n, char formate)
{
	int		size;
	char	*s;

	size = Calc_size(n);
	if (size > 8)
		size = 8;
	s = malloc(size + 1);
	if (!s)
		return ;
	Converter(s, n, size, formate);
	ft_putstr_fd(s, 1);
	free(s);
}

void	print_hex_ptr(unsigned long int n)
{
	int		size;
	char	*s;

	size = Calc_size(n);
	if (size > 8)
		size = 12;
	s = malloc(size + 1);
	if (!s)
		return ;
	Converter(s, n, size, 'x');
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(s, 1);
	free(s);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		printed_i;

	printed_i = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c' && str[i++])
		{
			printed_i++;
			ft_putchar_fd(va_arg(ap, int), 1);
		}
		else if (str[i] == '%' && str[i + 1] == 's' && str[i++])
		{
			//printed_i = ft_strlen(va_arg(ap, char *));
			ft_putstr_fd(va_arg(ap, char *), 1);
		}
		else if (str[i] == '%' && str[i + 1] == 'p' && str[i++])
			print_hex_ptr(va_arg(ap, long));
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i')
				&& str[i++])
			ft_putnbr_fd(va_arg(ap, int), 1);
		else if (str[i] == '%' && str[i + 1] == 'u' && str[i++])
			ft_putunsigned(va_arg(ap, unsigned int));
		else if (str[i] == '%' && (str[i + 1] == 'x' || str[i + 1] == 'X')
				&& str[i++])
			print_hex(va_arg(ap, int), str[i]);
		else if (str[i] == '%' && str[i + 1] == '%' && str[i++])
			ft_putstr_fd("%", 1);
		else if (str[i] == '%')
			return (0);
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(ap);
	return (i);
}
