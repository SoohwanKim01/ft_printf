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
