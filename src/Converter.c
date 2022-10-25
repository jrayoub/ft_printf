#include "ft_printf.h"
// x && X
void	Converter(unsigned long int n, int index, char format)
{
	if (n == 0)
		ft_putchar_fd('0', 1);
	index -= 1;
	if (n >= 16)
		Converter(n / 16, index, format);
	ft_putchar_fd((n % 16 < 10 ? 48 : (format == 120 ? 87 : 55)) + (n % 16), 1);
}