#include "libasm.h"

int		main()
{
	test_ft_strlen();	
}

void	test_ft_strlen()
{
	const char *string;

	string = "This is a sentence";
	printf("Length of : [%s]\n", string);
	printf("<string.h> strlen function: [%lu]\n", strlen(string));
	printf("'libasm.h' ft_strlen function: [%lu]\n", ft_strlen(string));
}
