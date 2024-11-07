NAME		= get_next_line.a

SRC		= get_next_line.c get_next_line_utils.c

OBJ		= $(SRC:.c=.o)

CC		= cc
CFLAGS		= -Wall -Werror -Wextra

AR		= ar -rc

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
	$(AR) $< $@

%.o:		%.c ./get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
