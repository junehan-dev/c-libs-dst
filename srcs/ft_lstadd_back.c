/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:35:48 by jihhan            #+#    #+#             */
/*   Updated: 2020/10/21 16:33:36 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_list.h"

void                ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  **lst_pt;

    if (!lst || !new)
        return;

    lst_pt = lst;

    while (*lst_pt++ != NULL);

    if (*(lst_pt + 1) != NULL)
        return;

    *lst_pt = new;
}
