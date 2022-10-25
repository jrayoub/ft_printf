#include "ft_printf.h"

void	print_hex(unsigned long int n, char formate, int *i)
{
	int size;

	size = Calc_size(n, 16);
	if (size > 8)
		size = 8;
	Converter(n, size, formate);
	*i = size;
}