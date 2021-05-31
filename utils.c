#include "utils.h"

void	*ft_dummy_sum(int n)
{
	if (n)
		n++;
	return (0);
}

int	ft_free(void *p)
{
	free(p);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*add(char *str, char c)
{
	int		i;
	char	*ret;

	if (!str)
		return (0);
	ret = (char *)malloc(ft_strlen(str) + 2);
	if (!ret)
		return (ft_dummy_sum(ft_free(str)));
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = c;
	ret[i + 1] = 0;
	return (ret);
}

static int	ft_dgts(long int n)
{
	int	div;
	int	i;

	div = 1;
	i = 0;
	if (n < 0)
		i = 1;
	if (n < 0)
		n *= -1;
	if (n < 10)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			dgts;
	int			min;
	long int	n2;
	char		*p;

	dgts = ft_dgts(n);
	p = (char *)malloc(dgts + 1);
	if (!p)
		return (0);
	min = 0;
	if (n < 0)
		min = 1;
	p[0] = '-';
	p[dgts] = 0;
	n2 = n;
	if (n < 0)
		n2 *= -1;
	while (--dgts >= min)
	{
		p[dgts] = n2 % 10 + 48;
		n2 /= 10;
	}
	return (p);
}

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*ret;

	ret = (char *)malloc(ft_strlen(str));
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = str[i];
	return (ret);
}

int	ft_atoi(const char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str++ <= '9')
		ret = *(str - 1) - 48 + 10 * ret;
	return (ret * sign);
}
