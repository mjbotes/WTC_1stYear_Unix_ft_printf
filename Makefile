FILENAMES	+= ft_conversions.c ft_flags.c ft_intconversions.c ft_printer.c ft_unicode.c ft_converters.c 
FILENAMES	+= ft_format.c ft_modifier.c ft_printf.c

NAME	 	=	libftprintf.a

LIBFT		=	libft/libft.a
CC			=	gcc
CFLAGS		=	

SRCS		=	$(addprefix srcs/, $(FILENAMES))
OBJS		=	$(addprefix build/, $(FILENAMES:.c=.o))

.PHONY:		all clean fclean re

all: $(NAME) 

build:
	mkdir $@

build/%.o: srcs/%.c | build
	$(CC) $(CFLAGS) -I includes/ -c $< -o $@

$(NAME): $(OBJS) 
	ar -x libft/libft.a
	ar rcs $@ $(OBJS) *.o
	ranlib $@
	rm *.o

clean:
	rm -rf build/
	rm -rf __.SYMDEF\ SORTED
	rm -rf __.SYMDEF

fclean: clean
	rm -f $(NAME)

re: fclean all
