/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:17:32 by junehan           #+#    #+#             */
/*   Updated: 2022/05/14 21:28:31 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_stack.h"

struct stack 	*make_stack(size_t siz, unsigned int len)
{
	struct stack	*ret;

	ret			= malloc(sizeof(struct stack));
	ret->siz	= siz;
	ret->len	= len;
	ret->cur	= 0;
	ret->data	= (void *)malloc(siz * len);

	return (ret);	
}

