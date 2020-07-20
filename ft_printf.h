/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:05:53 by sookim            #+#    #+#             */
/*   Updated: 2020/07/20 21:05:54 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

# define CONVS	"cspdiuxX%"
# define FLAGS	"-0.*123465789"
# define HEX_MA	"0123456789ABCDEF"
# define HEX_MI	"0123456789abcdef"
# define DEC	"0123456789"
# define FALSE 0

typedef	struct		s_node
{
	int		left;
	int		zeros;
	int		width;
	int		widthright;
	int		widthleft;
	int		precision;
	int		dot;
	int		dotleft;
	int		dotright;
}					t_flags;

int ft_printf(const char *format, ...);
int ft_nbrbase(unsigned long int nb, char *base, int print);
int ft_printp(unsigned long int p, t_flags flags);
int ft_printi(int n, t_flags flags);
int ft_printc(int c, t_flags flags);
int ft_prints(char *s, t_flags flags);
int ft_printux(unsigned int u, char *base, t_flags flags);

#endif