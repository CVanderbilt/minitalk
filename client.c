#include "utils.h"

void	ft_send(int pid, int *p)
{
	int i;

	i = -1;
	while (++i < 7)
	{
		if (p[i])
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1);
	}
}

void	ft_send_char(int pid, int c)
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
	ft_send(pid, n);
}

void	ft_send_word(int pid, const char *str)
{
	while (*str)
	{
		ft_send_char(pid, *str);
		str++;
	}
	ft_send_char(pid, 0);
}

int main(int argc, const char *argv[])
{
	int pid;
	int p[7];

	pid = ft_atoi(argv[1]);
	p[0] = 1;
	p[1] = 1;
	p[2] = 0;
	p[3] = 1;
	p[4] = 0;
	p[5] = 0;
	p[6] = 0;
	ft_send(pid, p);
	p[0] = 0;
	p[1] = 0;
	p[3] = 0;
	ft_send(pid, p);
/*
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_send_word(pid, argv[2]);
	return (0);
*/
}