#include "./src/ft_printf.h"

int	main(int ac, char **av)
{
	unsigned int	a;
	int				ft_i;
	int				i;

	a = 78;
	ft_i = ft_printf("%s yeasaah %d ...... %p", "Hellow", 77898798, &ft_i);
	printf("\n");
	i = printf("%s yeasaah %d ...... %p", "Hellow", 77898798, &ft_i);
	printf("\n\nft_i =  %d\ni    =  %d\n", ft_i, i);
}
