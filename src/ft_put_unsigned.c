#include "ft_printf.h"

void	ft_put_unsigned(unsigned int num, int *i)
{
	char c;

	if (num >= 10)
		ft_put_unsigned(num / 10, i);
	c = '0' + num % 10;
	write(1, &c, 1);
	(*i)++;
}