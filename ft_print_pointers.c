#include "ft_printf.h"

static int	find_sizep(unsigned long int p, t_flags flags)
{
	int size;

	size = 0;
	if (p)
	{
		if (ft_nbrbase(p, HEX_MI, 0) > flags.widthright)
			size = ft_nbrbase(p, HEX_MI, 0) + 2;
		else if (flags.widthright > 0 && flags.widthright < 11)
			size = flags.widthright + 2;
		else
			size = 11;
	}
	else
		size = (flags.widthright > 3) ? (flags.widthright + 2) : 3;
	if (flags.dot && flags.widthright == 0)
		size = 2;
	return (size);
}

int			ft_printp(unsigned long int p, t_flags flags)
{
	int		i;
	char	c;
	int		size;

	c = ' ';
	size = find_sizep(p, flags);
	if ((flags.zeros || flags.dot) && (flags.widthleft < flags.widthright))
		c = '0';
	if (!flags.left && !(i = 0))
		while (i++ < flags.widthleft - size)
			ft_putchar_fd(c, 1);
	if (p && !flags.zeros && !(flags.widthleft < flags.widthright))
		ft_putstr_fd("0x", 1, size, flags.dot);
	if (!p || (flags.widthleft < flags.widthright))
	{
		ft_putstr_fd("0x0", 1, size, flags.dot);
		while (i++ < (flags.widthright - ft_nbrbase(p, HEX_MI, 0)))
			ft_putchar_fd('0', 1);
	}
	if (p)
		ft_nbrbase(p, HEX_MI, 1);
	if (flags.left && !(i = 0))
		while (i++ < flags.widthleft - size)
			ft_putchar_fd(c, 1);
	return (flags.widthleft > size) ? (flags.widthleft) : (size);
}
