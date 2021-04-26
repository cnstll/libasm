NAME = libft.a

SRCS

OBJS = $(SRCS:.c=.o)

HEADERS = libft.h

CPLHEADERS = libft.h.gch

CC = nasm

LINKER = ld

NASMSFLAGS = -f elf64

BONUSOBJS = $(BONUSSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) $(HEADERS)
test : $(OBJS)
.c.o:
	$(CC) -c $(CFLAGS) $^

clean :
	rm -f $(OBJS) $(BONUSOBJS) $(CPLHEADERS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

