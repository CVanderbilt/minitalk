#ifndef UTILS_H
# define UTILS_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	*ft_dummy_sum(int n);
int		ft_free(void *p);
int		ft_strlen(const char *str);
char	*add(char *str, char c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *str);
void	ft_putstr(const char *str);
int		ft_atoi(const char *str);

#endif