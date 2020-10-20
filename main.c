#include "libasm.h"

int		main()
{
	test_ft_strlen();
	test_ft_strcmp();
	test_ft_strcpy();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
}

void	test_ft_strlen()
{
	size_t		real;
	size_t		mine;
	const char	*string;

	string = "Test phrase";
	real = strlen(string);
	mine = ft_strlen(string);
	printf("\n###########\n ft_strlen \n###########\n");
	printf("Length of : [%s]\n", string);
	printf("<string.h> strlen function: [%lu]\n", real);
	printf("'libasm.h' ft_strlen function: [%lu]\n", mine);
}

void	test_ft_strcmp()
{
	int		real;
	int		mine;
	const char	*s1;
	const char	*s2;

	s1 = "ab";
	s2 = "abc";
	real = strcmp(s1, s2);
	mine = ft_strcmp(s1, s2);
	printf("\n###########\n ft_strcmp \n###########\n");
	printf("s1 : [%s] \t s2 : [%s]\n", s1, s2);
	printf("<string.h> strcmp function: [%d]\n", real);
	printf("'libasm.h' ft_strcmp function: [%d]\n", mine);
}

void	test_ft_strcpy()
{
	char            *real;
	char		*mine;
	const char	*src;

	src = "abc";
	real = calloc(ft_strlen(src) +1, 1);
	mine = calloc(ft_strlen(src) +1, 1);
	printf("\n###########\n ft_strcpy \n###########\n");
        printf("DST : [%s] \t SRC : [%s]\n", mine, src);
	real = strcpy(real, src);
	mine = ft_strcpy(mine, src);
	printf("<string.h> strcpy function: [%s]\n", real);
	printf("'libasm.h' ft_strcpy function: [%s]\n", mine);
}

void	test_ft_write()
{
	int		fd;
	char	*s;

	fd = 1;
	s = "blabla";
	printf("\n##########\n ft_write \n##########\n");
	printf("fd: [%d] \t string: [%s]\n", fd, s);
	printf("<unistd.h> write function: ");
	//printf("{%lu} \n", write(fd, s, ft_strlen(s)));
	printf("'libasm.h' ft_write function: ");
	printf("{%lu \n} ", ft_write(fd, s, ft_strlen(s)));

}

void	test_ft_read()
{
	int		fd;
	char	*s;

	fd = 0;
	s = calloc(1, 1);
	printf("\n##########\n ft_read \n##########\n");
	printf("fd: [%d] \t buffer: [%s]\n", fd, s);
	printf("<unistd.h> read function: ");
	read(fd, s, 1);
	printf("'libasm.h' ft_read function: ");
	ft_read(fd, s, 1);

}

void	test_ft_strdup()
{
	char	*real;
	char	*mine;
	const char	*src;

	src = "malloc and copy";
	real = strdup(src);
	mine = ft_strdup(src);
	printf("\n###########\n ft_strdup \n###########\n");
	printf("Source: [%s]\n", src);
	printf("<string.h> strdup function: [%s] \n", real);
	printf("'libasm.h' ft_strdup function: [%s] \n", mine);

}
