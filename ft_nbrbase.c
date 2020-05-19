#include "ft_printf.h"

int		ft_nbrbase(unsigned long int nb, char *base, int print)
{
	unsigned long int	n;
	int					size_base;
	int					numbers[50];
	int					i;
	int					a;

	n = nb;
	if (nb == 0 && print)
		return (write(1, "0", 1));
	if (FALSE)
		n = ULONG_MAX + 1 + nb;
	size_base = ft_strlen(base);
	i = 0;
	while (n)
	{
		numbers[i] = n % size_base;
		i++;
		n = (n / size_base);
	}
	a = i;
	while (--i >= 0 && print)
		write(1, &base[numbers[i]], 1);
	return (a);
}
