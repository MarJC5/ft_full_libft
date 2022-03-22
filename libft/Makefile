# COLORS
GREEN	= \033[0;32m
RED 	= \033[0;31m
ORANGE	= \033[0;33m
CYAN	= \033[0;36m
RESET	= \033[0m

SRCS_LIBFT_DIR	= 	./libft/
SRCS_LIBFT_FILES= 	ft_atoi.c \
					ft_atol.c \
					ft_bzero.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_memcmp.c \
					ft_memcpy.c\
					ft_memchr.c \
					ft_memset.c \
					ft_memmove.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strchr.c \
					ft_strncmp.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_strdup.c \
					ft_calloc.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_itoa.c \
					ft_split.c \
					ft_strtrim.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c

SRCS_LIBFT		= 	${patsubst %, ${SRCS_LIBFT_DIR}%, ${SRCS_LIBFT_FILES}}

SRCS_GNL_DIR	= 	./gnl/
SRCS_GNL_FILES	= 	get_next_line.c \
				  	get_next_line_utils.c
SRCS_GNL		= 	${patsubst %, ${SRCS_GNL_DIR}%, ${SRCS_GNL_FILES}}

SRCS_PRT_DIR	= 	./ft_printf/
SRCS_PRT_FILES	= 	ft_printf.c \
				  	ft_printf_char.c \
				  	ft_printf_math.c \
					ft_printf_utils.c
SRCS_PRT		= 	${patsubst %, ${SRCS_PRT_DIR}%, ${SRCS_PRT_FILES}}

HEADS			= 	-I.
OBJS			= 	${SRCS_LIBFT:.c=.o} ${SRCS_GNL:.c=.o} ${SRCS_PRT:.c=.o}

NAME			= 	libft.a

CC				= 	gcc
RM				=	rm -f

CFLAGS			= 	-Wall -Wextra -Werror

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${HEADS}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo "[$(ORANGE)libft$(RESET)] Creation *.o files & compilation : $(GREEN)OK$(RESET)"

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean:	clean
	@${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re