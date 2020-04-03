#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern size_t	ft_strlen(const char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *dst, const char *src);
extern ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
extern ssize_t	ft_read(int fildes, void *buf, size_t nbyte);


void	test_ft_strlen();
void	test_ft_strcmp();
void	test_ft_strcpy();
void	test_ft_write();
void	test_ft_read();

