/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:23:56 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/10 15:47:42 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_list.h"

t_list              *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *next;
    t_list  *new;
    void    *res;

    if (!lst || !f || !del)
        return (NULL);

    next = lst->next;

    while (next)
    {
        lst->next = next->next;
        new = (res = f(next->content)) ? ft_lstnew(res) : lst->next;
        if (new != lst->next)
            new->next = lst->next;
        del(next->cotent);
        free(next);
        next = new->next;
    }

    new = (res = f(lst->content)) ? ft_lstnew(res) : lst->next;

    if (new != lst->next)
        new->next = lst->next;

    del(lst);
    free(lst);
    return (new);
}

