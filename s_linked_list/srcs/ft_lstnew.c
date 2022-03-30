/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:23:42 by jihhan            #+#    #+#             */
/*   Updated: 2020/10/19 19:04:19 by jihhan           ###   ########.fr       */
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

    ret->content = NULL;
    ret->next = NULL;
    
    if (content)
        ret->content = strdup((const char *)content);

    return (ret);
}

