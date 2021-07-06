NAME =

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I.

LIBFT = ./libft/libft.a

SRCFILE =


SRCDIRS = $(dir $(SRCFILE))
OBJDIR = ./obj
BINDIRS = $(addprefix $(OBJDIR)/, $(SRCDIRS))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.o))
TEST = $(notdir $(basename $(SRCFILE)))

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

minilibx:
	$(MAKE) do_configure -C ./minilibx-linux

$(NAME): $(OBJECTS) $(LIBFT) minilibx
	gcc -g $(CFLAGS) $^ $(INCLUDES) -L./minilibx-linux \
	-lft -lmlx -lXext -lX11 -lm -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(BINDIRS)
	gcc -g $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEST): $(OBJECTS) $(LIBFT)
	gcc -g $(filter tests/%/test_$@.c, $(TESTFILE)) \
	$(filter-out obj/srcs/main/main.o, $^) $(INCLUDES) -o test

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJECTS)
	$(RM) -rf $(OBJDIR)

fclean:
	$(MAKE) fclean -C ./libft
	$(RM) $(OBJECTS) $(NAME)
	$(RM) -rf $(OBJDIR)
	$(RM) -rf test test.dSYM

re: fclean all

.PHONY: all clean fclean re libft minilibx
