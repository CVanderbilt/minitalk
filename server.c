#include "server.h"
#include "utils.h"

void	ft_proces_word(void)
{
	char	*aux;

	aux = add(g_data->word, g_data->value);
	free (g_data->word);
	if (!aux)
		exit(1);
	g_data->word = aux;
	if (g_data->value == 0)
	{
		ft_putstr(g_data->word);
		write(1, "\n", 1);
		free(g_data->word);
		g_data->word = ft_strdup("");
	}
	g_data->value = 0;
	g_data->dgts_received = 0;
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		g_data->dgts_received++;
	if (signum == SIGUSR2)
	{
		g_data->value += g_data->arr[g_data->dgts_received];
		g_data->dgts_received++;
	}
	if (g_data->dgts_received == 7)
	{
		ft_proces_word();
	}
}

void	ft_lock(void)
{
	struct sigaction	act;

	act.sa_handler = sig_handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
}

int	main(void)
{
	t_data	d;
	char	*p;

	ft_lock();
	g_data = &d;
	d.arr[0] = 64;
	d.arr[1] = 32;
	d.arr[2] = 16;
	d.arr[3] = 8;
	d.arr[4] = 4;
	d.arr[5] = 2;
	d.arr[6] = 1;
	d.value = 0;
	d.dgts_received = 0;
	p = ft_itoa(getpid());
	if (!p)
		return (1);
	d.word = ft_strdup("");
	if (!d.word)
		return (1 + ft_free(p));
	ft_putstr(p);
	write(1, "\n", 1);
	free(p);
	while (1)
		sleep(1000);
}
