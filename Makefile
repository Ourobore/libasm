SRCS		= $(DIR)/ft_strlen.s

DIR			= ./srcs

OBJS		:= ${SRCS:.c=.o}

INCLUDES	= -Ilibasm.h

NASM		= nasm

NASMFLAGS	= -f elf

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

NAME		= libasm.a

.s.o		:
			  $(NASM) $(NASMFLAGS) -c $< -o $(<:.s=.o) $(INCLUDES)

all			: $(NAME)

$(NAME)		: $(OBJS)
			  ar -rcs $(NAME) $(OBJS)

test		: all
			  $(CC) $(CFLAGS) main.c $(NAME) $(INCLUDES)

clean		: $(OBJS)
			  rm -rf $(OBJS)

fclean		: clean
			  rm -rf a.out $(NAME)

re			: fclean all

.PHONY		: all test clean fclean re
