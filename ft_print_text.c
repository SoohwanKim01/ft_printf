/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:05:41 by sookim            #+#    #+#             */
/*   Updated: 2020/07/20 21:31:13 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(int c, t_flags flags)
{
	int		size;
	char	space;

	size = 0;
	space = ' ';
	if (flags.zeros)
		space = '0';
	if (!flags.left && !flags.dot)
		while (size++ < flags.widthleft - 1)
			ft_putchar_fd(space, 1);
	ft_putchar_fd(c, 1);
	if (flags.left)
		while (size++ < flags.widthleft - 1)
			ft_putchar_fd(space, 1);
	if (flags.widthleft)
		return (flags.widthleft);
	return (1);
}

int	ft_prints(char *s, t_flags flags)
{
	int		str_size;
	int		size;
	char	space;

	if (!s)
	{
		s = (char *)malloc(7 * sizeof(*s));
		s = "(null)";
	}
	if (((str_size = ft_strlen(s)) > flags.widthright) && flags.dot)
		str_size = (flags.widthright >= 0) ? flags.widthright : str_size;
	size = 0;
	space = ' ';
	if (flags.zeros)
		space = '0';
	if (!flags.left)
		while (size++ < flags.widthleft - str_size)
			ft_putchar_fd(space, 1);
	str_size = ft_putstr_fd(s, 1, str_size, flags.dot);
	if (flags.left)
		while (size++ < flags.widthleft - str_size)
			ft_putchar_fd(space, 1);
	if (flags.widthleft > str_size)
		return (flags.widthleft);
	return (str_size);
}
