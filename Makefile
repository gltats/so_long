#Colors--------------------
BLUE = \033[94m
ORANGE = \033[38;5;215m
RED = \033[31m
GREEN = \033[38;5;82m
RESET = \033[0m
#--------------------------

# Directories
LIBFT = ./libft
MLX = ./minilibx
GNL = ./gnl

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I ./inc -I $(LIBFT) -I $(MLX) -I $(GNL)
LIB = -L $(LIBFT) -lft -L $(MLX) -lm -framework OpenGL -framework Appkit
REMOVE = rm -f

# Source files
SRC = src/so_long.c src/validate.c

# Object files
OBJ = $(SRC:src/%.c=obj/%.o)
GNL_SRC = $(GNL)/get_next_line_bonus.c $(GNL)/get_next_line_utils_bonus.c
GNL_OBJ = $(GNL_SRC:$(GNL)/%.c=obj/%.o)

# Binary name
NAME = so_long

all: header $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ)
	@echo "$(RESET)$(ORANGE)Compiling LIBFT...$(RESET)"
	make -C $(LIBFT)
	@echo "$(RESET)$(ORANGE)Compiling Get_next_line...$(RESET)"
	make -C $(GNL)
	@echo "$(RESET)$(ORANGE)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIB)
	@echo "$(RESET)$(GREEN)DONE ✓✓$(RESET)"

# This rule specifies that for each object file in $(OBJ), 
# make should look for a source file in the src directory with 
# the same name but with a .c extension, compile it into an object file and 
# put the result in the obj directory. 
# The | obj part tells make that the obj directory should be created first if it doesn't exist.
$(OBJ): obj/%.o : src/%.c | obj
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(GNL_OBJ): obj/%.o : $(GNL)/%.c | obj
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

obj:
	@mkdir -p $@
	
header:	
		@echo "                                                    "
		@echo "$(BLUE)		 ___________________________________________________ $(BLUE)"
		@echo "$(BLUE)		|                                                   | $(BLUE)"
		@echo "$(BLUE)		|    *****  ***          *            *             | $(RESET)"
		@echo "$(BLUE)		|   *** **   **          *      **    *     ****    | $(RESET)"
		@echo "$(BLUE)		|   **  **   **         *****  **** *****   ****    | $(RESET)"
		@echo "$(BLUE)		|   **       **         *****  *  * *****  **  *    | $(RESET)"
		@echo "$(BLUE)		|   ** ***   **          *     ****   *    ****     | $(RESET)"
		@echo "$(BLUE)		|   ** ***   **          *    *****   *     ****    | $(RESET)"
		@echo "$(BLUE)		|   *** **   **    **    ** * **  *   **** **  **   | $(RESET)"
		@echo "$(BLUE)		|    ***** *****   **    **** ******  **** *****    | $(RESET)"
		@echo "$(BLUE)		|     **** *****   **    ****  *****  ***  *****    | $(RESET)"
		@echo "$(BLUE)		|___________________________________________________|$(RESET)"
		@echo "$(BLUE)		|__________________________________________$(RED)PROJECT!$(RESET)$(BLUE)_|$(RESET)"

cleanobj:
	$(RM) -r obj/

cleanlib:
	make clean -C $(LIBFT)
	make clean -C $(GNL)

fcleanlib:
	make fclean -C $(LIBFT)
	make fclean -C $(GNL)

clean: cleanobj cleanlib
	@echo "$(RESET)$(ORANGE)Cleaning object files...$(RESET)"
	${REMOVE} $(OBJ)
	@echo "$(RESET)$(GREEN)CLEANED ✓✓$(RESET)"

fclean: clean fcleanlib
	@echo "$(RESET)$(ORANGE)Cleaning object files and program...$(RESET)"
	${REMOVE} $(NAME)
	@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re: fclean all

.PHONY: all cleanobj clean fclean re
