#ifndef ft_PRINTF_H
# define ft_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		Calc_size(unsigned long int n, int base);
void	Converter(unsigned long int n, int index, char format);
void	ft_put_unsigned(unsigned int num, int *i);
void	print_hex(unsigned long int n, char formate, int *i);
void	print_ptr_adress(unsigned long int n, int *i);

#endif
