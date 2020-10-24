SRCS		= $(DIR)/ft_strlen.s \
			  $(DIR)/ft_strcmp.s \
			  $(DIR)/ft_strcpy.s \
			  $(DIR)/ft_write.s	 \
			  $(DIR)/ft_read.s	 \
			  $(DIR)/ft_strdup.s

DIR			= ./srcs

OBJS		:= ${SRCS:.s=.o}

INCLUDES	= -I .

NASM		= nasm

NASMFLAGS	= -f elf64

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

NAME		= libasm.a

.s.o		:
			  $(NASM) $(NASMFLAGS) $< -o $(<:.s=.o) $(INCLUDES)

all			: $(NAME)

$(NAME)		: $(OBJS)
			  ar -rcs $(NAME) $(OBJS)
			  ranlib $(NAME)

test		: all
			  $(CC) $(CFLAGS) -no-pie -g main.c $(NAME) $(INCLUDES)

clean		:
			  rm -rf $(OBJS) myfile1 myfile2

fclean		: clean
			  rm -rf a.out $(NAME)

re			: fclean all

.PHONY		: all test clean fclean re
