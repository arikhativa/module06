# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:56:52 by yrabby            #+#    #+#              #
#    Updated: 2023/06/18 16:38:24 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 					= test

# class
CLASS_DIR				= .
CLASS_NAME				= Base A B C

# other src
OTHER_SRC				= 

# main
SRC_MAIN				= main

# src
SRC_SUFFIX				= .cpp
SRC_DIR					= .
SRC_NAME				= $(addsuffix $(SRC_SUFFIX), $(CLASS_NAME) $(SRC_MAIN) $(OTHER_SRC))
SRC						= $(addprefix $(SRC_DIR)/, $(SRC_NAME))

# other header
OTHER_HEAD				= 

# head
HEAD_SUFFIX				= .hpp
HEAD_DIR				= .
HEAD_NAME				= $(addsuffix $(HEAD_SUFFIX), $(CLASS_NAME))
HEAD					= $(addprefix $(HEAD_DIR)/, $(HEAD_NAME))

# obj
OBJ_DIR					= .
OBJ						= $(SRC:.cpp=.o)

# flags
CC 						= c++
CFLAGS 					= -c -Wshadow -Wall -Wextra -Werror  -std=c++98 -pedantic -I $(HEAD_DIR)

# implicit rules
$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.cpp) $(HEAD)
	$(CC) $(CFLAGS) $< -o $(@)

# rules
.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all


