#include "utils.h"

void	ft_send(int pid, int *p)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		if (p[i])
		{
			if (kill(pid, SIGUSR2) < 0)
				exit (1);
		}
		else
			if (kill(pid, SIGUSR1) < 0)
				exit (1);
		usleep(150);
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

int	main(int argc, const char *argv[])
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	ft_send_word(pid, argv[2]);
	ft_putstr("mensaje: ");
	ft_putstr(argv[2]);
	write(1, "\n", 1);
	return (0);
}
