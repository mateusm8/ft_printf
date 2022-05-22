NAME = 		libftprintf.a


SRCS = 		ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strlen.c \


OBJS = 		$(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.

RM			= rm -f


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
