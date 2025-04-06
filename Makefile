CC = cc

FLAGS = -Wall -Werror -Wextra

NAME = minitalk

NAME_1 = client

NAME_2 = server



LIB_PATH =	libft

SRC_PATH =	src

OBJ_PATH =	obj



LIB_NAME =	libft.a

SRC_NAME =	server.c client.c

OBJ_NAME = $(SRC_NAME:.c=.o)



INC =	libft/include/libft.h 			\
		libft/include/ft_printf.h

SRC =	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ =	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

LIB =	$(addprefix $(LIB_PATH)/, $(LIB_NAME))

INC_FLAGS =	-Iinclude -Ilibft/include/



all: $(NAME)

$(NAME): $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_PATH)/client.o $(LIB)
	$(CC) $(FLAGS) $(OBJ_PATH)/client.o $(LIB) -o $(NAME_1)

$(NAME_2): $(OBJ_PATH)/server.o $(LIB)
	$(CC) $(FLAGS) $(OBJ_PATH)/server.o $(LIB) -o $(NAME_2)

$(LIB):
	$(MAKE) -C $(LIB_PATH)


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) -o $@ -c $< $(INC_FLAGS)
	@echo $<
	
clean:
	$(MAKE) -C $(LIB_PATH) fclean
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME_1) $(NAME_2)

re: fclean all

.PHONY : all clean fclean re
