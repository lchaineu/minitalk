#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	i;
	char			c;

	i = n;
	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		i = -n;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		c = i + '0';
		write(1, &c, 1);
	}
}
