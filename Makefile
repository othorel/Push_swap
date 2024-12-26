NAME            = push_swap
BONUS_NAME      = checker

LIBFT           = ./libft/libft.a

INC             = inc/
SRC_DIR         = srcs/
SRC_BONUS_DIR   = srcs_bonus/
OBJ_DIR         = obj/

CC              = gcc
CFLAGS          = -Wall -Werror -Wextra -I $(INC)

RM              = rm -f

SRCS            = $(SRC_DIR)commands/push.c \
                  $(SRC_DIR)commands/rev_rotate.c \
                  $(SRC_DIR)commands/rotate.c \
                  $(SRC_DIR)commands/sort_turk.c \
                  $(SRC_DIR)commands/sort_3.c \
                  $(SRC_DIR)commands/swap.c \
                  $(SRC_DIR)push_swap/handle_errors.c \
                  $(SRC_DIR)push_swap/init_a_to_b.c \
                  $(SRC_DIR)push_swap/init_b_to_a.c \
                  $(SRC_DIR)push_swap/main.c \
                  $(SRC_DIR)push_swap/stack_init.c \
                  $(SRC_DIR)push_swap/stack_utils.c \
                  $(SRC_DIR)push_swap/split.c

BONUS_SRCS      = $(SRC_BONUS_DIR)checker_bonus.c \
                  $(SRC_BONUS_DIR)utils_bonus.c \
                  $(SRC_DIR)commands/push.c \
                  $(SRC_DIR)commands/rev_rotate.c \
                  $(SRC_DIR)commands/rotate.c \
                  $(SRC_DIR)commands/swap.c \
                  $(SRC_DIR)push_swap/handle_errors.c \
                  $(SRC_DIR)push_swap/split.c \
                  $(SRC_DIR)push_swap/stack_init.c \
                  $(SRC_DIR)push_swap/stack_utils.c

OBJS            = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
BONUS_OBJS      = $(BONUS_SRCS:$(SRC_BONUS_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Executable $(NAME) created."

bonus: $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "Executable $(BONUS_NAME) created."

$(LIBFT):
	@$(MAKE) -C ./libft
	@echo "Libft compiled."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_BONUS_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C ./libft clean
	@echo "Objects cleaned."

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C ./libft fclean
	@echo "Everything cleaned."

re: fclean all

.PHONY: all bonus clean fclean re
