NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

HEADER_SRCS	=	pipex.h pipex_bonus.h
HEADER_DIR	=	Includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	pipex.c childs.c error.c free.c
MPATH_DIR	=	Src/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS	=	pipex_bonus.c error_bonus.c here_doc_bonus.c\
				files_bonus.c free_bonus.c child_bonus.c
BPATH_DIR	=	Bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c
FUNC_DIR	=	Fonctions/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))\
				GNL/get_next_line_utils.c GNL/get_next_line.c
OBJ_F		=	$(FUNC:.c=.o)

%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_M)
				@$(CC) $(OBJ_F) $(OBJ_M) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

bonus:			$(OBJ_F) $(OBJ_B)
				@$(CC) $(OBJ_F) $(OBJ_B) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_F)
				@$(RM) $(OBJ_B)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
