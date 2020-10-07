/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:35:48 by jihhan            #+#    #+#             */
/*   Updated: 2020/10/07 10:41:22 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"

void                ft_lstadd_back(t_list **lst, t_list *new);
{
    t_list **lst_pt;

    if (!lst)
        return;

    lst_pt = lst;

    while (*lst_pt)
        lst_pt++;

    *lst_pt = new;
    *(lst_pt + 1) = NULL;
}
