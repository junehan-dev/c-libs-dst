#ifndef __STACK_H
#define __STACK_H
#include <unistd.h>
#include <stdlib.h>
struct stack {
	size_t			siz;
	unsigned int	max;
	unsigned int	cur;
	void			*data;
}

struct stact	*make_stack(size_t siz, unsigned int max);
unsigned int	stack_push(struct stack s, void *src);
int				stack_pop(struct stack s);
#endif

int		main(void)
{
	struct stack	*my_stack;

	my_stack = make_stack(1, 4);
	char *data = (char*)my_stack->data;
	*data = 'a';
	*(data + 1) = 'b';
	*(data + 2) = 'c';
	*(data + 3) = '\0';
	printf("%s\n", (char *)my_stack->data);
	printf("max:%u cur:%u, siz:%ld\n", my_stack->max,my_stack->cur, my_stack->siz);

	free(my_stack->data);
	free(my_stack);
	return 0;
}
/
