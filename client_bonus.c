#include "utils.h"
#include "server.h"
#include <stdio.h>

void	ack(int s)
{
	if (s == SIGUSR1)
	{
		ft_putstr("server ack\n");
		exit(0);
	}
}

int	main(int argc, const char *argv[])
{
	if (argc != 3)
		return (1);
	signal(SIGUSR1, ack);
	ft_putstr("mensaje: ");
	ft_putstr(argv[2]);
	write(1, "\n", 1);
	send_msg(ft_atoi(argv[1]), argv[2]);
	usleep(1000);
	return (0);
}
