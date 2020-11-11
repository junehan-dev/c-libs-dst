/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:23:56 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/11 18:14:18 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_list.h"

t_list              *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    void    *res;
    t_list  *cur, *back, *next;

    if (!lst || !f || !del)
        return (NULL);

    back = NULL;
    cur = lst;
    next = cur; 

    while (!back && cur)
    {
        cur = (res = f(cur->content)) ? ft_lstnew(res) : next;
        if (cur != next)
        {
            cur->next = next->next;
            back = cur;
        }
        cur = next->next;
        del(next->content);
        free(next);
        next = cur;
    }

    lst = back;

    if (!cur)
        return (lst);

    while (next)
    {
        cur = (res = f(cur->content)) ? ft_lstnew(res) : next;
        if (cur != next)
        {
            back->next = cur;
            cur->next = next->next;
            back = cur;
        }
        cur = next->next;
        del(next->content);
        free(next);
        next = cur;
    }

    return (lst);
}

