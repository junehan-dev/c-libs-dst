/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:33:38 by jihhan            #+#    #+#             */
/*   Updated: 2020/10/21 16:38:37 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"

void                ft_lstadd_front(t_list **lst, t_list *new)
{
    t_list **lst_pt;
    t_list *temp;
    t_list *next;

    if (!lst || !new)
        return;

    lst_pt = lst;
    next = new;

    while (next && *lst_pt)
    {
        temp = *lst_pt;
        *lst_pt = next;
        next = temp;
        lst_pt++;
    }

    if (*(lst_pt + 1) != NULL)
    {
        free(next);
        return;
    }    

    *lst_pt = next;
}
