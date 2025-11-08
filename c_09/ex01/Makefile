FILES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJECTS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

TARGET = libft.a

all :$(TARGET)

$(TARGET) : $(OBJECTS)
	ar rc $(TARGET) $(OBJECTS)

%.o : %.c includes/ft.h
	cc -Wall -Wextra -Werror -I includes -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all