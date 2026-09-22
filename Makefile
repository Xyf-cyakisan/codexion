.PHONY: clean all fclean re

NAME= codexion
OBJ_DIR = Objects
FILES = codexion.c \
	   general_utils.c \
	   memory_management.c \
	   parsing_utils.c \
	   parsing.c \
	   heap_utils.c \
	   simulation.c

OBJS = $(FILES:%.c=$(OBJ_DIR)/%.o)

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror -pthread $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	cc -Wall -Wextra -Werror -pthread -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all