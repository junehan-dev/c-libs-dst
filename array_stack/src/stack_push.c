/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:29:03 by junehan           #+#    #+#             */
/*   Updated: 2022/05/14 21:30:11 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

unsigned int	stack_push(struct stack *s, const void *src)
{
	const char	*src_data;
	char		*top;
	size_t		n;

	if ((s->cur) == (s->len))
		return 0;

	n = 0;
	src_data = (const char *)src;
	top = (char *)(s->data) + (s->cur) * (s->siz);
	while (n < (s->siz)) {
		*(top + n) = *(src_data + n);
		n++;
	}
	s->cur++;

	return (n);
}

