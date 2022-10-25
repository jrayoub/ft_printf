#include "ft_printf.h"

void	print_ptr_adress(unsigned long int n, int *i)
{
	int size;

	size = Calc_size(n, 16);
	if (size > 8)
		size = 12;
	ft_putstr_fd("0x", 1);
	Converter(n, size, 'x');
	*i += size + 2;
}