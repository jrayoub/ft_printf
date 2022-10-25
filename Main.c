#include "./src/ft_printf.h"

int	main(void)
{
	unsigned int	a;

	a = 78;
	ft_printf("variable a address id : '%p' and its value is : '%u' \n", &a, a);
	printf("variable a address id : '%p' and its value is : '%s' \n", &a, a);
}
