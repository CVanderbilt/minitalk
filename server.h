#ifndef SERVER_H
# define SERVER_H

typedef struct s_data
{
	unsigned int	dgts_received;
	char			value;
	int				arr[7];
	int				cpid;
	char			*word;
}	t_data;

t_data	*g_data;
int		send_msg(int pid, const char *msg);

#endif