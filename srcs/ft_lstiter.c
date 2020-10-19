/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:05:09 by jihhan            #+#    #+#             */
/*   Updated: 2020/10/19 18:46:28 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"

void                ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list      *lst_pt;

    lst_pt = lst;
    while (lst_pt)
    {
        f(lst_pt->content);
        lst_pt = lst_pt->next;
    }
}
