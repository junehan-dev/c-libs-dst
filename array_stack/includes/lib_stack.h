#ifndef __STACK_H
#define __STACK_H
#include <unistd.h>
struct stack {
	size_t			siz;
	unsigned int	len;
	unsigned int	cur;
	void			*data;
};

struct stack	*make_stack(size_t siz, unsigned int len);
unsigned int	stack_push(struct stack *s, const void *src);
unsigned int	stack_pop(struct stack *s, void *dest );
#endif

