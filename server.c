#include "server.h"
#include "utils.h"

void	sig_handler(int signum)
{
	write(1, "sig catched\n", 12);
	if (signum == SIGUSR1)
		g_data->dgts_received++;
	if (signum == SIGUSR2)
	{
		g_data->value += g_data->arr[g_data->dgts_received];
		g_data->dgts_received++;
	}
	if (g_data->dgts_received == 7)
	{
		ft_putstr("received ");
		ft_putstr(ft_itoa(g_data->value));
		write(1, "\n", 1);
		add(g_data->word, g_data->value);
		if (!g_data->word)
			exit(1);
		if (g_data->value == 0)
		{
			write(1, "a", 1);
			ft_putstr(g_data->word);
			write(1, "a\n", 2);
			free(g_data->word);
			g_data->word = ft_strdup("");
		}
		else
			write(1, "kk\n", 3);
		g_data->value = 0;
		g_data->dgts_received = 0;
	}
}

void	ft_lock(void)
{
	struct sigaction act;

	act.sa_handler = sig_handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
}

int main(int argc, const char *argv[])
{
	t_data d;
	char *p;

	ft_lock();
	g_data = &d;
	d.arr[0] = 68;
	d.arr[1] = 32;
	d.arr[2] = 16;
	d.arr[3] = 8;
	d.arr[4] = 4;
	d.arr[5] = 2;
	d.arr[6] = 1;
	signal(SIGUSR1,sig_handler);
	signal(SIGUSR2,sig_handler);
	p = ft_itoa(getpid());
	if (!p)
		return (1);
	d.word = ft_strdup("");
	if (!d.word)
		return (1 + ft_free(p));
	ft_putstr(p);
	free(p);
	while(1)
		pause();
}