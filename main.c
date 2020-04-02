#include "libasm.h"

int		main()
{
	test_ft_strlen();
	test_ft_strcmp();
	test_ft_strcpy();
}

void	test_ft_strlen()
{
	const char *string;

	string = "This is a sentence";
	printf("Length of : [%s]\n", string);
	printf("<string.h> strlen function: [%lu]\n", strlen(string));
	printf("'libasm.h' ft_strlen function: [%lu]\n", ft_strlen(string));
}

void	test_ft_strcmp()
{
	const char *s1;
	const char *s2;

	s1 = "ab";
	s2 = "abc";
	printf("s1 : [%s] \t s2 : [%s]\n", s1, s2);
	printf("<string.h> strcmp function: [%d]\n", strcmp(s1, s2));
	printf("'libasm.h' ft_strcmp function: [%d]\n", ft_strcmp(s1, s2));
}

void	test_ft_strcpy()
{
	char		*dst;
	const char	*src;

	dst = malloc(4);
	dst[0] = 0;
	dst[1] = 0;
	dst[2] = 0;
	dst[3] = 0;
	src = "abcde";
	printf("DST : [%s] \t SRC : [%s]\n", dst, src);
	printf("dst: %s \n", dst);
	printf("<string.h> strcpy function: [%s]\n", strcpy(dst, src));
	dst[0] = 0;
	dst[1] = 0;
	dst[2] = 0;
	dst[3] = 0;
	printf("'libasm.h' ft_strcpy function: [%s]\n", ft_strcpy(dst, src));
	printf("dst: %s \n", dst);
}
