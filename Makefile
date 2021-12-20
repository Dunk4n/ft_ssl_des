# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niduches <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 14:57:17 by niduches          #+#    #+#              #
#    Updated: 2021/09/13 15:24:14 by niduches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

SRC_DIRECTORY	=	./src/
INC_DIRECTORY	=	./include/
LIB_DIRECTORY	=	./libft/

BUILD_DIRECTORY	=	build

SRC_FILE_NAME	=	main.c			\
					command_type.c	\
					exec.c			\
					argument.c		\
					help.c			\
					utils.c			\
					md5.c			\
					sha224.c		\
					sha256.c		\
					sha384.c		\
					sha512.c		\
					rmd128.c		\
					rmd160.c		\
					rmd256.c		\
					rmd320.c		\
					blob.c			\
					whirlpool.c		\
					hash.c			\
					base64.c		\

SRC			=	$(addprefix $(SRC_DIRECTORY),$(SRC_FILE_NAME))

NAME		=	ft_ssl

OBJ			=	$(SRC:%.c=$(BUILD_DIRECTORY)/%.o)

CFLAGS		=	-I$(INC_DIRECTORY) -Wall -Wextra -Werror

CDEBUG_FLAGS	=	-I$(INC_DIRECTORY) -Wall -Wextra -g -no-pie
CDEBUG_FLAGS_FSANITIZE	=	-g -fsanitize=address -fsanitize=leak -fsanitize=pointer-compare -fsanitize=pointer-subtract -fsanitize=undefined

LDFLAGS		=	-L$(LIB_DIRECTORY) -lft

all:	$(NAME)

options:
	@echo "  CC       $(CC)"
	@echo "  CFLAGS   $(CFLAGS)"
	@echo "  LDFLAGS  $(LDFLAGS)"

$(BUILD_DIRECTORY)/%.o: %.c $(INC)
	@mkdir -p $(@D)
	@echo "  CC       $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIB_DIRECTORY) clean --no-print-directory
	@echo "  RM       $(BUILD_DIRECTORY)"
	@rm -rf $(BUILD_DIRECTORY)

fclean: clean
	@$(MAKE) -C $(LIB_DIRECTORY) fclean --no-print-directory
	@echo "  RM       $(NAME)"
	@rm -f $(NAME)

$(NAME): options $(OBJ)
	@$(MAKE) -C $(LIB_DIRECTORY) --no-print-directory
	@echo "  BUILD    $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

re:	fclean	all

debug:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) "CFLAGS=$(CDEBUG_FLAGS)" --no-print-directory

.PHONY: all options clean fclean re debug
