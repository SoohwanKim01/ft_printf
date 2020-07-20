/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:05:45 by sookim            #+#    #+#             */
/*   Updated: 2020/07/20 21:05:46 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	mod(t_flags flags, int d)
{
	if (flags.widthright < 0 && flags.dot)
		flags.dot = 0;
	if (d < 0 && flags.widthright < 0)
		flags.widthright = 0;
	return (flags);
}

static t_flags	ft_auxux(t_flags flags, int u, int size, int c)
{
	int	aux;
	int	i;

	flags = mod(flags, u);
	c = (flags.zeros || (flags.dot && flags.widthright)) ? '0' : c;
	if (!flags.left && flags.widthleft && !(i = 0))
	{
		c = (flags.dot && (flags.widthleft > flags.widthright)) ? ' ' : c;
		aux = (flags.widthright > size) ? (flags.widthright) : (size);
		while (i++ < flags.widthleft - aux)
			ft_putchar_fd(c, 1);
	}
	return (flags);
}

int				ft_printux(unsigned int u, char *base, t_flags flags)
{
	int		i;
	char	c;
	int		size;

	i = 0;
	c = ' ';
	size = (u == 0) ? 1 : ft_nbrbase(u, base, 0);
	size = (u == 0 && flags.dot && !flags.widthright) ? 0 : size;
	flags = ft_auxux(flags, u, size, c);
	if (flags.dot && flags.widthright && !(i = 0))
		while (i++ < flags.widthright - size)
			ft_putchar_fd('0', 1);
	size = (flags.widthright > size) ? (flags.widthright) : (size);
	if (!(u == 0 && flags.dot && !flags.widthright))
		ft_nbrbase(u, base, 1);
	i = 0;
	if (flags.left)
		while (i++ < flags.widthleft - size)
			ft_putchar_fd(' ', 1);
	return (flags.widthleft > size) ? (flags.widthleft) : (size);
}
