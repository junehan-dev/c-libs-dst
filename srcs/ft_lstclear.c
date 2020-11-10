/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:27:02 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/10 15:54:52 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_list.h"

void                ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *temp;

    if (!(*lst) || !del)
        return;

    temp = (*lst)->next;

    while (temp)
    {
        (*lst)->next = temp->next;
        del((temp->content));
        free(temp);
        temp = (*lst)->next;
    }
    del((*lst)->content);
    free(*lst);
}

