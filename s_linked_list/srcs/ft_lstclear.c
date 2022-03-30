/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:27:02 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/11 18:29:39 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_list.h"

void                ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *temp;
    t_list  *lst_pt;

    if (!(*lst) || !del)
        return;

    lst_pt = *lst;
    temp = lst_pt->next;

    while (lst_pt)
    {
        temp = lst_pt->next;
        del(lst_pt->content);
        free(lst_pt);
        lst_pt = temp;
    }
}

