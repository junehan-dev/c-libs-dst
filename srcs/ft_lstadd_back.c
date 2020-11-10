/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:35:48 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/10 15:51:03 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"

void                ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *temp;
    
    if (!(*lst) || !new)
        return;

    temp = ft_lstlast(*lst);
    temp->next = new;
    new->next = NULL;
}

