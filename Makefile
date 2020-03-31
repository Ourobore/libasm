$(SRCS)			: $(DIR)/ft_strlen.s

$(DIR)			: ./srcs

$(INCLUDES)		: -Ilibasm.h

$(NASM)			: nasm

$(NASMFLAGS)	: -f elf

$(CC)			: gcc

$(CFLAGS)		: -Wall -Werror -Wextra

$(LIBASM)		: libasm.a

.s.o			:
				  $(NASM) $(NASMFLAGS) -c $< -o $(<:.s=.o) $(INCLUDES)

clean			: 
