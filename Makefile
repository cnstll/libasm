NAME = libasm.a

SRCS = srcs/ft_strlen.s \
		srcs/ft_strcpy.s \
		srcs/ft_strcmp.s \
		srcs/ft_read.s \
		srcs/ft_write.s \
		srcs/ft_strdup.s \

OBJS = $(SRCS:.s=.o)

ASM = nasm

NASMSFLAGS = -f elf64

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
.s.o:
	$(ASM) $(NASMSFLAGS) $^

clean :
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
