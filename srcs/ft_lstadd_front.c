/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:33:38 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/10 15:04:28 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"

void                ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!(*lst) || !new)
        return;

    new->next = *lst;
    *lst = new;
}
