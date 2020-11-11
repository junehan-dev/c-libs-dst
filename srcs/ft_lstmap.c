/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:23:56 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/11 17:48:42 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_list.h"

t_list              *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *next;
    t_list  *new;
    t_list  *res;
    t_list  *ret;

    if (!lst || !f || !del)
        return (NULL);

    ret = NULL;
    new = lst;
    next = new;

    while (!ret && new)
    {
        new = (res = f(new->content)) ? ft_lstnew(res) : next;
        if (new != next)
        {
            new->next = next->next;
            ret = new;
        }
        new = next->next;
        del(next->content);
        free(next);
        next = new;
    }

    if (!new)
        return (ret);

    while (new)
    {
        new = (res = f(new->content)) ? ft_lstnew(res) : next;
        if (new != next)
            new->next = next->next;
        new = next->next;
        del(next->content);
        free(next);
        next = new;
    }

    return (ret);
}

