/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:17:32 by junehan           #+#    #+#             */
/*   Updated: 2022/05/14 00:54:30 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct stack {
	size_t			siz;
	unsigned int	max;
	unsigned int	cur;
	void			*data;
};

struct stack 	*make_stack(size_t siz, unsigned int max)
{
	struct stack	*ret;

	ret			= (struct stack *)malloc(sizeof(struct stack));
	ret->siz	= siz;
	ret->max	= max;
	ret->cur	= 0;
	ret->data	= (void *)malloc((ret->max) * 4);

	return (ret);	
}

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
