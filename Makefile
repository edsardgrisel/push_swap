NAME=push_swap
CC=cc
CFLAGS=-Wall -Werror -Wextra -g
SRCS=main.c
OBJS=$(SRCS:.c=.o)
LIBFT_DIR=./libft
LIBFT_ARCHIVE=$(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re bonus

all: $(LIBFT_ARCHIVE) $(NAME)

$(LIBFT_ARCHIVE):
	$(MAKE) -s -C $(LIBFT_DIR) bonus
	$(MAKE) -s -C $(LIBFT_DIR) clean

$(NAME): $(OBJS) $(LIBFT_ARCHIVE)
	cc $(CFLAGS) $(OBJS) $(LIBFT_ARCHIVE) -o $(NAME)

clean:
	rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean


re:  fclean all