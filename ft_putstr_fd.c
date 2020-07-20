/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:06:00 by sookim            #+#    #+#             */
/*   Updated: 2020/07/20 21:06:01 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd, int size, int flag)
{
	int	n;

	n = 0;
	if (s)
	{
		while (*s && (size > 0 || !flag))
		{
			ft_putchar_fd(*s, fd);
			s++;
			n++;
			size--;
		}
	}
	return (n);
}
