#include "utils.h"

static int	ft_send(int pid, int *p)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		if (p[i])
		{
			if (kill(pid, SIGUSR2) < 0)
				return (0);
		}
		else
			if (kill(pid, SIGUSR1) < 0)
				return (0);
		usleep(60);
	}
	return (1);
}

static int	ft_send_char(int pid, int c)
{
	int	n[7];

	n[6] = c % 2;
	c /= 2;
	n[5] = c % 2;
	c /= 2;
	n[4] = c % 2;
	c /= 2;
	n[3] = c % 2;
	c /= 2;
	n[2] = c % 2;
	c /= 2;
	n[1] = c % 2;
	c /= 2;
	n[0] = c % 2;
	return (ft_send(pid, n));
}

static int	ft_send_word(int pid, const char *str)
{
	while (*str)
	{
		if (!ft_send_char(pid, *str))
			return (0);
		str++;
	}
	return (ft_send_char(pid, 0));
}

int	send_msg(int pid, const char *msg)
{
	char	*cpid;
	int		r;

	cpid = ft_itoa(getpid());
	if (!cpid)
		return (0);
	r = ft_send_word(pid, cpid);
	free (cpid);
	if (!r)
		return (0);
	return (ft_send_word(pid, msg));
}
