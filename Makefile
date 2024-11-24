LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = so_long
SRC = 

MAIN = main.c
OBJ = $(SRC:.c=.o)
MAINOBJ = $(MAIN:.c=.o)


LIBFTNAME = libft.a
LIBFTDIR = ./libft
MLXNAME = libmlx_Linux.a
MLXDIR = ./mlx_linux
INCLUDE = so_long.h


all: $(NAME)

$(NAME): makelibft makemlx $(OBJ) $(MAINOBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(MAINOBJ) -Lmlx_linux -l mlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFTNAME) $(MLXNAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .

makemlx:
	@make -C $(MLXDIR)
	@make -f Makefile.gen -C $(MLXDIR)
	@cp $(MLXDIR)/$(MLXNAME) .

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -I/usr/include -Imlx_linux -O3 -c -o $@ $<

clean:
	$(RM) $(OBJ) $(MAINOBJ)
	@cd $(LIBFTDIR) && make clean
	@cd $(MLXDIR) && make clean

fclean: clean
	$(RM) $(NAME)
	@rm -f $(LIBFTNAME)
	@rm -f $(MLXNAME)

re: fclean all