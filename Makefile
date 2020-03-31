SRCS		= $(DIR)/ft_strlen.s

DIR			= ./srcs

OBJS		:= ${SRCS:.s=.o}

INCLUDES	= -Ilibasm.h

NASM		= nasm

NASMFLAGS	= -f macho64

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
			 #gcc main.c srcs/ft_strlen.o $(INCLUDES)
			  $(CC) $(CFLAGS) main.c $(NAME) $(INCLUDES)

clean		:
			  rm -rf $(OBJS)

fclean		: clean
			  rm -rf a.out $(NAME)

re			: fclean all

.PHONY		: all test clean fclean re
