NAME = fdf

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I.

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

SRCFILE =	srcs/render/render_map.c \
			srcs/utils/draw_line.c \
			srcs/utils/get_next_line.c \
			srcs/utils/render_utils.c \
			srcs/main.c


OBJDIR = ./obj
SRCDIRS = $(dir $(SRCFILE))
BINDIRS = $(addprefix $(OBJDIR)/, $(SRCDIRS))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.o))
TEST = $(notdir $(basename $(SRCFILE)))

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(MINILIBX):
	$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJECTS) $(LIBFT) $(MINILIBX)
	gcc -g $(CFLAGS) $^ $(INCLUDES) -lXext -lX11 -lm -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(BINDIRS)
	gcc -g $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEST): $(OBJECTS) $(LIBFT)
	gcc -g $(filter tests/%/test_$@.c, $(TESTFILE)) \
	$(filter-out obj/srcs/main/main.o, $^) $(INCLUDES) -o test

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(OBJECTS)
	$(RM) -rf $(OBJDIR)

fclean:
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(OBJECTS) $(NAME)
	$(RM) -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re libft minilibx
