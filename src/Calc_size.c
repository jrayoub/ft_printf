int	Calc_size(unsigned long int n, int base)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}
