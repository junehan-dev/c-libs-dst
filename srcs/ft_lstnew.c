/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:23:42 by jihhan            #+#    #+#             */
/*   Updated: 2020/10/17 17:25:20 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "s_list.h"

t_list              *ft_lstnew(void *content)
{
    t_list      *ret;

    ret = malloc(sizeof(t_list) * 1);
    if (!ret)
        return (NULL);
    ret->next = NULL;
    ret->content = strdup((char *)content);
    return (ret);
}

