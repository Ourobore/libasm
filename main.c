#include "libasm.h"

int		main()
{
	test_ft_strlen();
	test_ft_strcmp();
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

	s1 = "abc";
	s2 = "";
	printf("s1 : [%s] \t s2 : [%s]\n", s1, s2);
	printf("<string.h> strcmp function: [%d]\n", strcmp(s1, s2));
	printf("'libasm.h' ft_strcmp function: [%d]\n", ft_strcmp(s1, s2));
}
