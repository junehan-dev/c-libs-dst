CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -Iincludes -c
.DEFALT_GOAL		:= all
NAME				= s_list.a

SOURCES				= $(wildcard srcs/*.c)
HEADERS				= $(wildcard includes/*.h)
OBJECTS				= $(patsubst %.c, %.o, $(SOURCES))
TESTS				= $(wildcard tests/*.c)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

.PHONY: test
test: $(TESTS)
	$(CC) -Wall -Werror -Wextra -Iincludes tests/main.c $(NAME) -o tests/test.out
	./tests/test.out
	/bin/rm -f ./tests/test.out

.PHONY: clean
clean:
	/bin/rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY: re
re: fclean all

