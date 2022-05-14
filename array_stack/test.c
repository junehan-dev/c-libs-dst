#include <stdlib.h>
#include <stdio.h>
#include "lib_stack.h"

int		main(void)
{
	struct stack	*my_stack;
	char key;
	unsigned int ret;
	key = 'a';

	my_stack = make_stack(1, 32);
	ret = stack_push(my_stack, (const void *)(&key));
	printf("%c, %u pushed \n", key, ret);
	key = 'c';
	stack_pop(my_stack, (void *)(&key));
	printf("%c, %u poped \n", key, ret);

	free(my_stack->data);
	free(my_stack);
	return 0;
}
/*
struct stack	*make_stack(size_t siz, unsigned int max)
{
	struct stack *ret;
	ret = (struct stack*)malloc(sizeof(struct stack));
	if (!ret)
		return 0;

	ret->siz = siz;
	ret->max = max;
	ret->cur = 0;
	ret->data = (void *)malloc(siz * max);
	if (!ret->data) {
		free(ret);
		return 0;
	}

	return ret;
}

*/
