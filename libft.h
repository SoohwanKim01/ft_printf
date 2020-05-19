#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd, int size, int flag);
int				ft_putnbr_fd(int nbr, int fd, int print);

#endif
