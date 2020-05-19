#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;
	char	*s1;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	c1 = (char)c;
	s1 = (char *)s;
	while (s1[i] && s1[i] != c1)
		i++;
    if(s1[i] == c1)
        return (&s1[i]);
    return (NULL);
}
