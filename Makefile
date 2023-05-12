SRCS	=	main.c\
			src/hook.c\
			src/get_info.c\
			src/get_acl.c\
			src/get_obj.c\
			src/err.c\
			src/make_origin_to_cam.c\
			src/make_cam_orient_to_my_orient.c\
			src/make_img.c\
			src/basic.c\
			src/basic1.c\
			src/basic2.c\
			src/basic3.c\
			src/3vector/translation.c\
			src/3vector/rotation.c\
			src/3vector/v3asic1.c\

OBJS	=	${SRCS:.c=.o}

CC		=	cc -Wall -Wextra -Werror

NAME	=	miniRT

HEADER	=	minirt.h

RM		=	rm -f

MLX_NAME	=	mlx

MLX_DIR		=	includes/minilibx

MLX			=	$(addprefix $(MLX_DIR)/, libmlx.dylib)

CLIB		=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit -Imlx

# colors

DEF_COLOR	=	\033[0;39m
CYAN		=	\033[3;96m
GREEN		=	\033[1;92m
MAGENTA		=	\033[3;95m
YELLOW		=	\033[1;93m
BLUE		=	\033[1;94m
GRAY		=	\033[2;90m
WHITE		=	\033[1;97m
RED			=	\033[3;91m

all		:	$(NAME)

%.o		:	%.c
			@echo "${GRAY}compiling $<...${DEF_COLOR}"
			@$(CC) -I$(MLX_DIR) -c $< -o $@

$(NAME)	:	$(OBJS) $(MLX)
			@cp $(MLX) .
			@$(CC) $(CLIB) -o $(NAME) $(OBJS)
			@echo "${YELLOW}All files are compiled !!${DEF_COLOR}"
			@echo "✅ ${GREEN}FdF executable file made !${DEF_COLOR}"

clean	:
			@${RM} ${OBJS}
			@echo "${CYAN}object files cleaned !${DEF_COLOR}"

fclean	:	clean
			@${RM} libmlx.dylib
			@echo  "${MAGENTA}libmlx.dylib file cleaned!${DEF_COLOR}"
			@${RM} ${NAME}
			@echo "❌${RED}FdF excutable file cleaned !${DEF_COLOR}"

re		:	fclean
			@$(MAKE) all
			@echo "${BLUE}Cleaned and Rebuilt all files !${DEF_COLOR}"

.PHONY	:	all clean fclean re .c.o
