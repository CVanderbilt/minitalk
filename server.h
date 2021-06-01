#ifndef SERVER_H
# define SERVER_H

typedef struct s_data
{
	unsigned int	dgts_received;
	char			value;
	int				arr[7];
	char			*word;
}	t_data;

t_data	*g_data;

#endif