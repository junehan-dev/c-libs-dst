CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -Iincludes
.DEFAULT_GOAL		:= all
NAME				= lib_stack.a

SOURCES				= $(wildcard src/*.c)
OBJECTS				= $(patsubst %.c, %.o, $(SOURCES))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

.PHONY: clean
clean:
	/bin/rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: test
test: 
	$(CC) $(CFLAGS) ./test.c $(NAME) -o test.run
