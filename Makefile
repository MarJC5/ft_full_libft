# COLORS
GREEN	= \033[0;32m
RED 	= \033[0;31m
ORANGE	= \033[0;33m
CYAN	= \033[0;36m
RESET	= \033[0m

SRCS_DIR	= ./src/
SRCS_FILES	=  main.c
SRCS_FILES	+= 

SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

O_DIR		= ./objs/
D_DIR		= ./debugs/
HEADS		= -I./includes/ -I./libft

OBJS_FILES	:= ${SRCS_FILES:.c=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}
DEBUGS		:= ${patsubst %, ${D_DIR}%, ${OBJS_FILES}}

VALGRIND	= valgrind  --main-stacksize=167104768 --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=memcheckignore --gen-suppressions=yes
VALGRIND	= valgrind  --suppressions=memcheckignore --gen-suppressions=yes

LIBFT		= ./libft
MAKELIB		= ${MAKE} -C ${LIBFT}
OBJS		+= ${LIBFT}/libft.a
DEBUGS		+= ${LIBFT}/libft.a

NAME		= PROGRAM_NAME

CC			= cc
AR			= ar rcs
MKDIR		= mkdir
CP			= cp -f
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

all: ${NAME}

#Compile normal executable
${NAME}: ${O_DIR} ${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
	@echo "[$(ORANGE)$(NAME)$(RESET)] Creation *.o files & compilation : $(GREEN)OK$(RESET)"
	@echo "[\033[1;32msuccess$(RESET)]: $(NAME) is ready"

#Create objects directory
${O_DIR}:
	@${MKDIR} ${O_DIR}

#Compile normals objects
${O_DIR}%.o: ${SRCS_DIR}%.c
	@${CC} ${CFLAGS} ${HEADS} -o $@ -c $<

#Compile libft
${LIBFT}/libft.a:
	@${MAKELIB} all

#Compile and use valgrind
valgrind: ${D_DIR} ${DEBUGS}
	${RM} ${NAME}
	${CC} ${CFLAGS} -o ${NAME} ${DEBUGS} ${LIBS} -ggdb
	${VALGRIND} ./${NAME}


#Compile a debug executable with -g and fsanitize
debug: ${D_DIR} ${DEBUGS} 
	${MAKELIB} all
	${CC} ${CFLAGS} -fsanitize=address -o ${NAME} ${DEBUGS} ${LIBS}

#Create debug directory
${D_DIR}:
	@${MKDIR} ${D_DIR}

#Compile debug objects
${D_DIR}%.o:${SRCS_DIR}%.c
	@${CC} ${CFLAGS} -g ${HEADS} -o $@ -c $<

clean:
	@${RM} ${OBJS} ${OBJSB} ${DEBUGS}
	@${RM} -r ${O_DIR}
	@${RM} -r ${D_DIR}
	@${MAKELIB} clean
	@echo "[$(ORANGE)libft$(RESET)] clean *.o files : $(GREEN)OK$(RESET)"
	@echo "[$(ORANGE)$(NAME)$(RESET)] clean *.o files : $(GREEN)OK$(RESET)"

fclean:	clean
	@${RM} ${NAME}
	@${RM} -r ${NAME}.dSYM
	@${MAKELIB} fclean
	@echo "[$(ORANGE)libft$(RESET)] fclean : $(GREEN)OK$(RESET)"
	@echo "[$(ORANGE)$(NAME)$(RESET)] fclean: $(GREEN)OK$(RESET)"
	@echo "[\033[1;32msuccess$(RESET)]: $(NAME) has been clean up"

re: fclean all

.PHONY: all clean fclean re debug valgrind

##################################################
## 			MINILIBX MAIN VERSION 				##
##################################################
# SRCS_DIR	= ./src
# SRCS_FILES	=  main.c
# SRCS_FILES	+= 

# SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

# O_DIR		= ./objs/
# D_DIR		= ./debugs/
# HEADS		= -I./includes/ -I./libft -I./minilibx


# OBJS_FILES	:= ${SRCS_FILES:.c=.o}
# OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}
# DEBUGS		:= ${patsubst %, ${D_DIR}%, ${OBJS_FILES}}

# VALGRIND	= valgrind  --main-stacksize=167104768 --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=memcheckignore --gen-suppressions=yes
# VALGRIND	= valgrind  --suppressions=memcheckignore --gen-suppressions=yes


# LIBFT		= ./libft
# MAKELIB		= ${MAKE} -C ${LIBFT}
# OBJS		+= ${LIBFT}/libft.a
# DEBUGS		+= ${LIBFT}/libft.a


# LIBX		= ./minilibx
# MAKELIBX	= ${MAKE} -C ${LIBX}
# OBJS		+= ${LIBX}/libmlx.a
# DEBUGS		+= ${LIBX}/libmlx.a

# LIBS		= -framework OpenGL -framework AppKit


# NAME		= PROGRAM_NAME
# ifeq (${OS},Windows_NT)
# 	NAME	:= ${NAME:=.exe}
# endif

# CC			= cc
# AR			= ar rcs
# MKDIR		= mkdir
# CP			= cp -f
# RM			= rm -f

# CFLAGS		= -Wall -Wextra -Werror



# all:		${NAME}

# #Compile normal executable
# ${NAME}:	${O_DIR} ${OBJS}
# 			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

# #Create objects directory
# ${O_DIR}:
# 			${MKDIR} ${O_DIR}

# #Compile normals objects
# ${O_DIR}%.o:${SRCS_DIR}%.c
# 			${CC} ${CFLAGS} ${HEADS} -o $@ -c $<

# #Compile libft
# ${LIBFT}/libft.a:
# 			${MAKELIB} all

# #Compile minilibx
# ${LIBX}/libmlx.a:
# 			${MAKELIBX} all



# #Compile and use valgrind
# valgrind:	${D_DIR} ${DEBUGS}
# 			${RM} ${NAME}
# 			${CC} ${CFLAGS} -o ${NAME} ${DEBUGS} ${LIBS} -ggdb
# 			${VALGRIND} ./${NAME}


# #Compile a debug executable with -g and fsanitize
# debug:		${D_DIR} ${DEBUGS} 
# 			${MAKELIB} all
# 			${MAKELIBX} all
# 			${CC} ${CFLAGS} -fsanitize=address -o ${NAME} ${DEBUGS} ${LIBS}

# #Create debug directory
# ${D_DIR}:
# 			${MKDIR} ${D_DIR}

# #Compile debug objects
# ${D_DIR}%.o:${SRCS_DIR}%.c
# 			${CC} ${CFLAGS} -g ${HEADS} -o $@ -c $<


# clean:
# 			${RM} ${OBJS} ${OBJSB} ${DEBUGS}
# 			@${RM} -r ${O_DIR}
# 			@${RM} -r ${D_DIR}
# 			@${MAKELIB} clean
# 			@${MAKELIBX} clean

# fclean:		clean
# 			${RM} ${NAME}
# 			@${RM} -r ${NAME}.dSYM
# 			@${MAKELIB} fclean

# re:			fclean all

# .PHONY:		all clean fclean re debug valgrind