#include "libft.h"

int		ft_putnbr_fd(int n, int fd, int print)
{
	long	nb;
	int		size;
	int		numbers[50];
	int		i;

	nb = n;
	size = 0;
	if (n == 0)
	{
		if (print)
			ft_putchar_fd('0', fd);
		return (1);
	}
	if (nb < 0)
		nb *= -1;
	while (nb)
	{
		numbers[size++] = nb % 10;
		nb = nb / 10;
	}
	i = size;
	while (--i >= 0 && print)
		ft_putchar_fd((char)(numbers[i] + '0'), fd);
	return ((n > 0) ? size : (size + 1));
}
