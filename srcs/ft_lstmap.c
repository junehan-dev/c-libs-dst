/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:23:56 by jihhan            #+#    #+#             */
/*   Updated: 2020/10/12 18:53:27 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_list.h"

t_list              *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list      *lst_pt;
    t_list      *buf;
    t_list      **lst_arr;
    int         i;

    lst_pt = lst;
    lst_arr = (t_list **)malloc(sizeof(t_list *) * (ft_lstsize(lst) + 1));

    if (!lst_arr || !lst)
        return (NULL);

    while (lst_pt)
    {
        buf = NULL;
        if (!f(lst_pt->content))
        {
            buf = lst_pt->next;
            ft_lstdelone(lst_pt, del);
        } else
            ft_lstadd_back(lst_arr, lst_pt); 
        lst_pt = (lst_pt) ? lst_pt->next : buf;
    }
    ft_lstadd_back(lst_arr, NULL);
 
    lst_pt = *lst_arr;
    i = 1;

    while (lst_pt)
    {
        lst_pt->next = *(lst_arr + i++);
        lst_pt = lst_pt->next;
    }
    lst_pt = *lst_arr;
    free(lst_arr);
    return (lst_pt);
}
