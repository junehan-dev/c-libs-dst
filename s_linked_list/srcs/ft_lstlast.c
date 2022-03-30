/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:01:22 by jihhan            #+#    #+#             */
/*   Updated: 2020/11/10 15:54:14 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_list.h"

t_list              *ft_lstlast(t_list *lst)
{
    t_list      *lst_pt;

    if (!lst)
        return (NULL);

    lst_pt = lst;
        
    while (lst_pt->next)
        lst_pt = lst_pt->next;

    return (lst_pt);
}
