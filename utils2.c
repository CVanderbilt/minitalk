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
