# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/28 16:43:33 by pedde-so          #+#    #+#              #
#    Updated: 2025/05/28 16:43:36 by pedde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC_FILES	= push_swap push_swap_utils moves_swap
LIBFT		= libft
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include
NAME		= push_swap

CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)
LDFLAGS		= -L$(LIBFT) -lft

SRC			= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -g $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -s -C $(LIBFT)
	@make bonus -s -C $(LIBFT)
	@$(CC) -g $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -s -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME) libft.a
	@make fclean -s -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

