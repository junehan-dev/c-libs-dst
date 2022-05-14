/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:52:36 by junehan           #+#    #+#             */
/*   Updated: 2022/05/14 21:22:15 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

unsigned int	stack_pop(struct stack *s, void *dest)
{
	char			*dest_data;
	const char		*top;
	unsigned int	n;

	if (!s->cur)
		return (0);

	n = 0;
	(s->cur)--;
	dest_data = (char *)dest;
	top = (const char *)(s->data) + (s->cur) * (s->siz);
	while (n < (s->siz)) {
		*(dest_data + n) = *(top + n);
		n++;
	}

	return (n);
}

