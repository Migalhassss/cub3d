# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 18:33:29 by diosanto          #+#    #+#              #
#    Updated: 2024/02/17 04:51:52 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	ft_strlen.c				\
			ft_atoi.c				\
			ft_strlen.c				\
			ft_bzero.c				\
			ft_calloc.c				\
			ft_isalnum.c			\
			ft_isalpha.c			\
			ft_isascii.c			\
			ft_isdigit.c			\
			ft_isprint.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_memcpy.c				\
			ft_memmove.c			\
			ft_memset.c				\
			ft_split.c				\
			ft_strchr.c				\
			ft_strdup.c				\
			ft_strjoin.c			\
			ft_strlcat.c			\
			ft_strlcpy.c			\
			ft_strncmp.c			\
			ft_strnstr.c			\
			ft_strrchr.c			\
			ft_strtrim.c			\
			ft_substr.c				\
			ft_tolower.c			\
			ft_toupper.c			\
			ft_itoa.c				\
			ft_strmapi.c			\
			ft_striteri.c			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_lstnew.c				\
			ft_lstadd_front.c		\
			ft_lstsize.c			\
			ft_lstlast.c			\
			ft_lstadd_back.c		\
			ft_lstdelone.c			\
			ft_lstclear.c			\
			ft_lstiter.c			\
			ft_lstmap.c				\
			get_next_line.c			\
			get_next_line_utils.c	\
			ft_trim_free.c


NAME 	=	libft.a
OBJECTS	=	$(SOURCES:.c=.o)
GCCW	=	gcc	-Wall -Wextra -Werror -I. -g

.c.o:
	$(GCCW) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)

clean:		
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re