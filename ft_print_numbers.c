/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:05:36 by sookim            #+#    #+#             */
/*   Updated: 2020/07/20 21:05:37 by sookim           ###   ########.fr       */
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

static t_flags	ft_auxi(int d, t_flags flags, int size, int c)
{
	int	aux;
	int	i;

	flags = mod(flags, d);
	if (d < 0 && flags.zeros && !flags.widthleft && !flags.widthright
			&& !flags.dot)
		ft_putchar_fd('-', 1);
	c = ((flags.zeros || (flags.dot && (flags.widthright > 0)))) ? '0' : c;
	if (d < 0 && (flags.zeros && flags.widthleft) && !flags.dot)
	{
		ft_putchar_fd('-', 1);
		flags.widthright++;
	}
	if (d < 0 && (!flags.zeros || flags.dot))
		flags.widthright++;
	if (!flags.left && flags.widthleft && !(i = 0))
	{
		c = (flags.dot && (flags.widthleft > flags.widthright)) ? ' ' : c;
		aux = (flags.widthright > size) ? (flags.widthright) : (size);
		while (i++ < flags.widthleft - aux)
			ft_putchar_fd(c, 1);
	}
	return (flags);
}

int				ft_printi(int d, t_flags flags)
{
	int		i;
	char	c;
	int		size;

	i = 0;
	c = ' ';
	size = ft_putnbr_fd(d, 1, 0);
	size = (d == 0 && flags.dot && !flags.widthright) ? 0 : size;
	flags = ft_auxi(d, flags, size, c);
	if (d < 0 && (!flags.zeros || flags.dot))
		ft_putchar_fd('-', 1);
	if (flags.dot && flags.widthright)
	{
		i = 0;
		while ((flags.widthright - size) > i++)
			ft_putchar_fd('0', 1);
	}
	size = (flags.widthright > size) ? (flags.widthright) : (size);
	if (!(d == 0 && flags.dot && !flags.widthright))
		ft_putnbr_fd(d, 1, 1);
	if (flags.left && !(i = 0))
		while (i++ < flags.widthleft - size)
			ft_putchar_fd(' ', 1);
	return (flags.widthleft > size) ? (flags.widthleft) : (size);
}
