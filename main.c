
#include "libasm.h"

int		main()
{
	test_ft_strlen();
	test_ft_strcmp();
	test_ft_strcpy();
	test_ft_write();
	//test_ft_read();
	test_ft_strdup();
}

void	test_ft_strlen()
{
	printf("\n\n\n########## FT_STRLEN ##########\n\n");
	
	//Normal string
	char	*s1 = "Test";
	printf("\n___STRING___\n");
	printf("\nString: \t[%s]\n", s1);
	printf("FT_STRLEN: \tReturn: [%ld]\n", ft_strlen(s1));
	printf("STRLEN: \tReturn: [%ld]\n", strlen(s1));
	
	//Empty string
	char	*s2 = "";
	printf("\n\n___EMPTY STRING___\n");
	printf("\nString: \t[%s]\n", s2);
	printf("FT_STRLEN: \tReturn: [%ld]\n", ft_strlen(s2));
	printf("STRLEN: \tReturn: [%ld]\n", strlen(s2));

	/*
	//NULL string
	char	*s3 = NULL;
	printf("\n\n___NULL STRING___\n");
	printf("\nString: \t[%s]\n", s3);
	printf("FT_STRLEN: \tReturn: [%ld]\n", ft_strlen(s3));
	printf("STRLEN: \tReturn: [%ld]\n", strlen(s3));
	*/
}

void	test_ft_strcmp()
{
	printf("\n\n\n########## FT_STRCMP ##########\n\n");

	char	*s1 = "abc";
	char	*s2 = "abd";
	
	//s1 to s2
	printf("\n___S1 TO S2___\n");
	printf("\nS1: [%s] \t S2: [%s]\n", s1, s2);
	printf("FT_STRCMP: \tReturn: [%d]\n", ft_strcmp(s1, s2));
	printf("STRCMP: \tReturn: [%d]\n", strcmp(s1, s2));

	//s2 to s1
	printf("\n\n___S1 TO S2___\n");
	printf("\nS2: [%s] \t S1: [%s]\n", s2, s1);
	printf("FT_STRCMP: \tReturn: [%d]\n", ft_strcmp(s2, s1));
	printf("STRCMP: \tReturn: [%d]\n", strcmp(s2, s1));

	//s1 to ""
	printf("\n\n___S1 TO EMPTY STRING___\n");
	printf("\nS1: [%s] \t S2: [%s]\n", s1, "");
	printf("FT_STRCMP: \tReturn: [%d]\n", ft_strcmp(s1, ""));
	printf("STRCMP: \tReturn: [%d]\n", strcmp(s1, ""));

	/*
	//s1 NULL
	char	*s3 = NULL;
	printf("\n\n___S1 TO NULL STRING___\n");
	printf("\nS1: [%s] \t S2: [%s]\n", s1, s3);
	printf("FT_STRCMP: \tReturn: [%d]\n", ft_strcmp(s1, s3));
	printf("STRCMP: \tReturn: [%d]\n", strcmp(s1, s3));
	*/
}

void	test_ft_strcpy()
{
	printf("\n\n\n########## FT_STRCPY ##########\n\n");

	char	*src = "I'm here! And there!";
	int		n = ft_strlen(src);
	char	*dest1;
	char	*dest2;

	//Src to dest
	printf("\n___SRC TO DEST___\n");
	dest1 = calloc(n, 1);
	dest2 = calloc(n, 1);
    printf("\nSRC : [%s] \t DEST : [%s]\n", src, dest1);
	dest1 = ft_strcpy(dest1, src);
	dest2 = strcpy(dest2, src);
	printf("FT_STRCPY: \tReturn: [%s]\n", dest1);
	printf("STRCPY: \tReturn: [%s]\n", dest2);
	free(dest1);
	free(dest2);

	//"" to dest
	src = "";
	printf("\n\n___SRC TO EMPTY STRING___\n");
	dest1 = calloc(n, 1);
	dest2 = calloc(n, 1);
	printf("\nSRC : [%s] \t DEST : [%s]\n", src, dest1);
	dest1 = ft_strcpy(dest1, src);
	dest2 = strcpy(dest2, src);
	printf("FT_STRCPY: \tReturn: [%s]\n", dest1);
	printf("STRCPY: \tReturn: [%s]\n", dest2);
	free(dest1);
	free(dest2);

	/*
	//NULL dest
	src = NULL;
	printf("\n\n___SRC TO NULL STRING___\n");
	dest1 = calloc(n, 1);
	dest2 = calloc(n, 1);
	printf("\nSRC : [%s] \t DEST : [%s]\n", src, dest1);
	dest1 = ft_strcpy(dest1, src);
	dest2 = strcpy(dest2, src);
	printf("FT_STRCPY:\tReturn: [%s]\n", dest1);
	printf("STRCPY: \tReturn: [%s]\n", dest2);
	free(dest1);
	free(dest2);
	*/
}

void	test_ft_write()
{
	printf("\n\n\n########## FT_WRITE ##########\n\n");

	char	*s = "I'm out!";
	int		ret;

	//Stdout
	printf("\nString: [%s]\n\n___STDOUT___\n\n", s);
	write(1, "FT_WRITE: \t", 11);
	ret = ft_write(1, s, ft_strlen(s));
	printf("\n\tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	errno = 0;
	write(1, "WRITE: \t\t", 9);
	ret = write(1, s, ft_strlen(s));
	printf("\n\tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	errno = 0;

	//Write on fd
	int		fd1;
	int		fd2;
	fd1 = open("myfile1", O_CREAT | O_WRONLY, S_IRWXU);
	fd2 = open("myfile2", O_CREAT | O_WRONLY, S_IRWXU);
	ret = ft_write(fd1, s, ft_strlen(s));
	printf("\n\n___WRITE ON FILE___\n");
	printf("\nFT_WRITE: \tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	errno = 0;
	ret = write(fd2, s, ft_strlen(s));
	printf("WRITE: \t\tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	errno = 0;
	close(fd1);
	close(fd2);

	//Write on wrong fd
	ret = ft_write(42, s, ft_strlen(s));
	printf("\n\n___WRITE ON WRONG FD___\n");
	printf("\nFT_WRITE: \tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	errno = 0;
	ret = write(42, s, ft_strlen(s));
	printf("WRITE: \t\tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	errno = 0;

	/*
	//NULL s
	s = NULL;
	printf("\n\n___NULL STRING___\n");
	printf("\nString: [%s]\n", s);
	write(1, "FT_WRITE: ", 10);
	ret = ft_write(1, s, ft_strlen(s));
	printf("\n\tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	errno = 0;
	write(1, "\nWRITE: ", 8);
	ret = write(1, s, ft_strlen(s));
	printf("\n\tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	errno = 0;
	*/
}

void	test_ft_read()
{
	printf("\n\n\n########## FT_READ ##########\n\n");

	char	*buf;
	int		n = 100;
	int		ret;

	buf = calloc(n, 1);

	//Stdin
	printf("\n___STDIN___\n\n");
	write(1, "FT_READ: \t", 10);
	ret = ft_read(1, buf, n);
	printf("\tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	bzero(buf, n);
	errno = 0;
	write(1, "READ: \t\t", 8);
	ret = read(1, buf, n);
	printf("\tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	bzero(buf, n);
	errno = 0;

	//Read on fd
	int		fd;
	fd = open("myfile1", O_RDONLY);
	printf("\n\n___READ FROM FILE___\n\n");
	ret = ft_read(fd, buf, n);
	printf("FT_READ: \t%s\n\tReturn: [%d] \t Errno: [%d]\n", buf, ret, errno);
	bzero(buf, n);
	errno = 0;
	close(fd);
	fd = open("myfile1", O_RDONLY);
	ret = read(fd, buf, n);
	printf("READ: \t\t%s\n\tReturn: [%d] \t Errno: [%d]\n", buf, ret, errno);
	bzero(buf, n);
	errno = 0;
	close(fd);

	//Read on wrong fd
	printf("\n\n___READ FROM WRONG FD___\n\n");
	ret = ft_read(42, buf, n);
	printf("FT_READ: \t%s\n\tReturn: [%d] \t Errno: [%d]\n", buf, ret, errno);
	bzero(buf, n);
	errno = 0;
	ret = read(42, buf, n);
	printf("READ: \t\t%s\n\tReturn: [%d] \t Errno: [%d]\n", buf, ret, errno);
	bzero(buf, n);
	errno = 0;

	/*
	//NULL s
	buf = NULL;
	printf("\n___NULL BUFF___\n\n");
	write(1, "FT_READ: \t", 10);
	ret = ft_read(1, buf, n);
	printf("\tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	bzero(buf, n);
	errno = 0;
	write(1, "READ: \t\t", 8);
	ret = read(1, buf, n);
	printf("\tReturn: [%d] \t Errno: [%d]\n", ret, errno);
	bzero(buf, n);
	errno = 0;
	*/
	free(buf);
}

void	test_ft_strdup()
{
	printf("\n\n\n########## FT_STRDUP ##########\n\n");
	
	char	*src = "What's up?";
	char	*dest;
	char	*dest2;

	//Non empty src
	printf("\n___STRING___\n");
	printf("\nSRC: [%s]\n", src);
	dest = ft_strdup(src);
	dest2 = strdup(src);
	printf("FT_STRDUP: \tReturn: [%s]\n", dest);
	printf("STRDUP: \tReturn: [%s]\n", dest2);
	free(dest);
	free(dest2);

	//Empty src
	char	*src2 = "";
	printf("\n\n___EMPTY STRING___\n");
	printf("\nSRC: [%s]\n", src2);
	dest = ft_strdup(src2);
	dest2 = strdup(src2);
	printf("FT_STRDUP: \tReturn: [%s]\n", dest);
	printf("STRDUP: \tReturn: [%s]\n", dest2);
	free(dest);
	free(dest2);

	/*
	//NULL src
	char	*src3 = NULL;
	printf("\n\n___NULL STRING___\n");
	printf("\nSRC: [%s]\n" ,src3);
	dest = ft_strdup(src3);
	dest2 = strdup(src3);
	printf("FT_STRDUP: \tReturn: [%s]\n", dest);
	printf("STRDUP: \tReturn: [%s]\n", dest2);
	free(dest);
	free(dest2);
	*/
}
