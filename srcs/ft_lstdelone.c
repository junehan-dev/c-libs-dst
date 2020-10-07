/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:08:24 by jihhan            #+#    #+#             */
/*   Updated: 2020/10/07 10:24:48 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"

void                ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst || !del)
        return;

    del(lst->content);
    free(lst);
}
