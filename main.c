#include "libasm.h"

int		main()
{
	test_ft_strlen();	
}

void	test_ft_strlen()
{
	char *string;

	string = "This is a sentence";
	printf("Length of : [%s]\n", string)
	printf("<string.h> strlen function: [%d]\n", strlen(string));
	printf("'libasm.h' ft_strlen function: [%d]\n", ft_strlen(string));
}
