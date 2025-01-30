NAME = push_swap
BONUS = checker

LIBFT_DIR = ./libft
LIBFT =  $(LIBFT_DIR)/libft.a
INC_D = /includes
SRC_DIR = srcs
BONUS_DIR = bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS = $(shell find $(SRC_DIR) -name "*.c")

BONUS_SRCS = $(shell find $(BONUS_DIR) -name "*.c")

OBJ_DIR = ps_build

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

RED     := "\033[1;31m"
GREEN   := "\033[1;32m"
RESET   := "\033[0m"

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I.$(INC_D) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(BONUS_OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(BONUS)
	@rm -rf $(OBJ_DIR)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re bonus re_bonus