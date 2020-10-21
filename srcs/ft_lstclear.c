/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:27:02 by jihhan            #+#    #+#             */
/*   Updated: 2020/10/21 15:27:43 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_list.h"

void                ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list      **lst_pt;

    if (!lst || !del)
        return;
    lst_pt = lst;

    while (*lst_pt)
    {
        del(((*lst_pt)->content));
        free(*lst_pt);
        lst_pt++;
    }
    free(lst);
}
