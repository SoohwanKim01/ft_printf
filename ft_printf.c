/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:05:47 by sookim            #+#    #+#             */
/*   Updated: 2020/07/20 21:05:48 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	start_flag(void)
{
	t_flags	flags;

	flags.left = 0;
	flags.zeros = 0;
	flags.width = 0;
	flags.widthright = 0;
	flags.widthleft = 0;
	flags.precision = 0;
	flags.dot = 0;
	flags.dotleft = 0;
	flags.dotright = 0;
	return (flags);
}

static t_flags	precision_flags(t_flags flags, int width)
{
	if (width < 0 && !flags.dot)
	{
		flags.left = 1;
		width *= -1;
	}
	if ((flags.precision = 1) && !flags.dot)
		flags.widthleft = width;
	else
		flags.widthright = width;
	return (flags);
}

static t_flags	check_flags(char c, va_list param_list, t_flags flags)
{
	if (ft_isdigit(c))
	{
		if (c == '0' && flags.widthleft == 0 && !flags.left)
			flags.zeros = 1;
		else if (!flags.precision && !flags.dot)
			flags.widthleft = flags.widthleft * 10 + c - '0';
		else if (flags.dot)
			flags.widthright = flags.widthright * 10 + c - '0';
		else if (!flags.widthleft)
			flags.zeros = 1;
	}
	if (c == '-')
	{
		flags.left = 1;
		flags.zeros = 0;
	}
	if (c == '.')
		flags.dot = 1;
	if (c == '*')
		flags = precision_flags(flags, va_arg(param_list, int));
	return (flags);
}

static int		check_conv(char c, va_list param_list, t_flags flags)
{
	int	size;

	if (c == 'c')
		size = ft_printc(va_arg(param_list, int), flags);
	else if (c == 's')
		size = ft_prints(va_arg(param_list, char *), flags);
	else if (c == 'p')
		size = ft_printp(va_arg(param_list, unsigned long int), flags);
	else if (c == 'i' || c == 'd')
		size = ft_printi(va_arg(param_list, int), flags);
	else if (c == 'u')
		size = ft_printux(va_arg(param_list, unsigned int), DEC, flags);
	else if (c == 'x')
		size = ft_printux(va_arg(param_list, unsigned int), HEX_MI, flags);
	else if (c == 'X')
		size = ft_printux(va_arg(param_list, unsigned int), HEX_MA, flags);
	else if (c == '%')
		size = ft_printc('%', flags);
	else
		return (-1);
	return (size);
}

int ft_printf(const char *format, ...)
{
    va_list	param_list;
	int		size;
	t_flags	flags;

	size = 0;
	va_start(param_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			flags = start_flag();
			format++;
			while (ft_strchr(FLAGS, *format))
				flags = check_flags(*format++, param_list, flags);
			if (*format)
				size = size + check_conv(*format++, param_list, flags);
		}
		if (*format && *format != '%')
		{
			ft_putchar_fd(*(format++), 1);
			size++;
		}
	}
	va_end(param_list);
	return (size);
}