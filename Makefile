LIBFT_SRC_FILES		=libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memcmp.c  libft/ft_putchar_fd.c libft/ft_split.c \
					libft/ft_strlcat.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_atoi.c libft/ft_isalpha.c \
					libft/ft_itoa.c libft/ft_memcpy.c  libft/ft_putendl_fd.c libft/ft_strchr.c  libft/ft_strlcpy.c \
					libft/ft_strnstr.c libft/ft_tolower.c libft/ft_bzero.c   libft/ft_isascii.c libft/ft_memcpy.c \
					libft/ft_memmove.c libft/ft_putnbr_fd.c  libft/ft_strdup.c  libft/ft_strlen.c  libft/ft_strrchr.c \
					libft/ft_toupper.c libft/ft_calloc.c  libft/ft_isdigit.c libft/ft_memchr.c  libft/ft_memset.c  \
					libft/ft_putstr_fd.c  libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_strtrim.c libft/ft_striteri.c

SRC_PRINTF			= src/ft_printf.c src/ft_calc_num_base_size.c src/ft_converter_base_hex.c src/ft_put_unsigned.c src/print_hex.c \
					src/print_ptr_adress.c

OBJ_FILES		= $(LIBFT_SRC_FILES:.c=.o)
PRINTF_OBJ_FILES		= $(SRC_PRINTF:.c=.o)

RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
AR				= ar rcs

NAME	= libftprintf.a



$(NAME): $(OBJ_FILES) $(PRINTF_OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES) $(PRINTF_OBJ_FILES)

all: $(NAME)

clean:
	$(RM) $(OBJ_FILES) $(PRINTF_OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)


.PHONY: all clean fclean re bonus
