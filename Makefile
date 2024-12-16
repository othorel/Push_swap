SRCS =  $(SRCS_DIR)/check.c                        \
		$(SRCS_DIR)/chunk_sort.c                  \
		$(SRCS_DIR)/do_move.c                     \
		$(SRCS_DIR)/main.c                        \
		$(SRCS_DIR)/move.c                        \
		$(SRCS_DIR)/position.c                    \
		$(SRCS_DIR)/push_pa_pb.c                  \
		$(SRCS_DIR)/rebverse_rotate_rra_rrb_rrr.c \
		$(SRCS_DIR)/rotate_ra_rb_rr.c             \
		$(SRCS_DIR)/sort.c                        \
		$(SRCS_DIR)/swap_sa_sb_ss.c               \
		$(SRCS_DIR)/t_stack.c                     \
		$(SRCS_DIR)/utils.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES_DIR)

OBJS = $(SRCS:.c=.o)

NAME = push_swap

SRCS_DIR = srcs

INCLUDES_DIR = includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re