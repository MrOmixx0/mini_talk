
CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRC_PATH =	src

OBJ_PATH =	obj

INCLUDES =	include/ft_printf.h			\
			include/get_next_line.h		\
			include/libft.h

SRC_NAME =	libft/ft_atoi.c					\
			libft/ft_bzero.c				\
			libft/ft_calloc.c				\
			libft/ft_isalnum.c				\
			libft/ft_isalpha.c				\
			libft/ft_isascii.c				\
			libft/ft_isdigit.c				\
			libft/ft_isprint.c				\
			libft/ft_itoa.c					\
			libft/ft_memchr.c				\
			libft/ft_memcmp.c				\
			libft/ft_memcpy.c				\
			libft/ft_memmove.c				\
			libft/ft_memset.c				\
			libft/ft_putchar_fd.c			\
			libft/ft_putendl_fd.c			\
			libft/ft_putnbr_fd.c			\
			libft/ft_putstr_fd.c			\
			libft/ft_split.c				\
			libft/ft_strchr.c				\
			libft/ft_strdup.c				\
			libft/ft_striteri.c				\
			libft/ft_strjoin.c				\
			libft/ft_strlcat.c				\
			libft/ft_strlcpy.c				\
			libft/ft_strlen.c				\
			libft/ft_strmapi.c				\
			libft/ft_strncmp.c				\
			libft/ft_strnstr.c				\
			libft/ft_strrchr.c				\
			libft/ft_strtrim.c				\
			libft/ft_substr.c				\
			libft/ft_toupper.c				\
			libft/ft_tolower.c				\
			libft/ft_lstadd_back.c			\
			libft/ft_lstadd_front.c			\
			libft/ft_lstclear.c				\
			libft/ft_lstdelone.c			\
			libft/ft_lstiter.c				\
			libft/ft_lstlast.c				\
			libft/ft_lstmap.c				\
			libft/ft_lstnew.c				\
			libft/ft_lstsize.c				\
			printf/ft_printf.c	  			\
			printf/ft_pointer.c				\
			printf/ft_printf.c				\
			printf/ft_putchar.c				\
			printf/ft_putnbr.c				\
			printf/ft_putstr.c				\
			printf/ft_putuxx.c				\
			gnl/get_next_line.c  			\
			gnl/get_next_line_utils.c

INC_FLAG = -I include

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $^
	@echo $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJ))
	@$(CC) $(FLAGS) -o $@ -c $< $(INC_FLAG)
	@echo $<
	
clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
