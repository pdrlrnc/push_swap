# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: you <you@42.fr>                             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 09:50:19 by you               #+#    #+#              #
#    Updated: 2025/07/18 10:10:00 by you               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

SRC_FILES   = push_swap algorithms_1 algorithms_3 clean_list moves_push \
	      moves_rotate moves_rotate_reverse moves_swap push_swap_utils parser \
	      algorithms_4 
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include

PRINTF_URL  = https://github.com/pdrlrnc/ft_printf.git
PRINTF_DIR  = ft_printf
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a

CC          = cc -g -O0
CFLAGS      = -Wall -Wextra -Werror -I$(INC_DIR)
RM          = rm -rf

RED=\033[0;31m
DEF_COLOUR=\033[0m

SRC         = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ         = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))
HDRS        = $(INC_DIR)/push_swap.h $(INC_DIR)/printf.h $(INC_DIR)/libft.h

.PHONY: all clean fclean re headers

all: $(PRINTF_LIB) headers $(NAME)
	@echo "$(RED)\
	 ____            _                                  \n\
	|  _ \ _   _ ___| |__      _____      ____ _ _ __   \n\
	| |_) | | | / __| '_ \    / __\ \ /\ / / _\` | '_ \  \n\
	|  __/| |_| \__ \ | | |   \__ \\ V  V / (_| | |_) | \n\
	|_|    \__,_|___/_| |_|___|___/ \_/\_/ \__,_| .__/  \n\
                     |_____|                |_|     $(DEF_COLOUR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDRS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@ctags -R .
	@echo "tags\n.gitignore\nchecker_linux" > .gitignore

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(OBJ) $(PRINTF_LIB)
	@$(CC) $(CFLAGS) $(OBJ) -L$(PRINTF_DIR) -lftprintf -o $(NAME)

$(PRINTF_DIR):
	@git clone --depth 1 $(PRINTF_URL) $(PRINTF_DIR)

$(PRINTF_LIB): | $(PRINTF_DIR)
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR)

headers: $(INC_DIR)/printf.h $(INC_DIR)/libft.h

$(INC_DIR)/printf.h: $(PRINTF_LIB)
	@mkdir -p $(INC_DIR)
	@cp $(PRINTF_DIR)/include/printf.h $(INC_DIR)/printf.h

$(INC_DIR)/libft.h: $(PRINTF_LIB)
	@mkdir -p $(INC_DIR)
	@cp $(PRINTF_DIR)/include/libft.h $(INC_DIR)/libft.h

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(INC_DIR)/printf.h $(INC_DIR)/libft.h 
	@$(RM) -r $(PRINTF_DIR)

re: fclean all

