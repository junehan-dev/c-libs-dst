#include <string.h>
#include <stdlib.h>
#include "s_list.h"
#include "dbg.h"

t_list  *test_creat(void *content);
int     test_delone(t_list *lst);
void    del_content(void *);
int test_lstsize(t_list *lst, size_t size);

int main(void)
{
    t_list      *created;
    t_list      *end;

    debug("TEST START---------");

    created = test_creat("~first created~");
    if (!created)
        exit(1);
    if(test_delone(created) == 1)
        exit(1);

    created = ft_lstnew("lst_start");
    end = created;
    end->next = ft_lstnew("lst_2");
    end = end->next;
    end->next = ft_lstnew("lst_3");
    end = end->next;
    test_lstsize(created, 3);

    debug("TEST END---------");
    return (0);
}

int test_lstsize(t_list *lst, size_t size)
{
    int     ret;
    t_list  *cur;
    t_list  *next;

    debug("----RUN: test_size:ft_lstsize----");
    cur = lst;
    next = cur -> next;
    ret = ft_lstsize(lst);
    check(
        ((size_t)ret == size),
        "1. t_list length non equal."
    );
    debug("----FIN: test_size:ft_lstsize----");

    while (cur)
    {
        free(cur);
        cur = next;
        next = next->next;
    }
    return (0);

error:
    debug("expected: %ld, actual: %d", size, ret);
    debug("----ERR: test_size:ft_lstsize----");

    while (cur)
    {
        free(cur);
        cur = next;
        next = next->next;
    }
    return (1);
}

int test_delone(t_list *lst)
{
    char    *content_pt;
    char    *str_buf;
    
    debug("----RUN: test_delone:ft_lstdelone----");
    content_pt = (char *)(lst->content);
    str_buf = strdup(content_pt);
    check(
        (strcmp(content_pt, str_buf) == 0),
        "0. content is copied safe, before freeing."
    );
    ft_lstdelone(lst, del_content);
    check(
        (strcmp(content_pt, str_buf) != 0),
        "1. content is not Freed"
    );
    free(str_buf);
    check(
        (sizeof(lst) != sizeof(t_list)),
        "2. lst is not Freed"
    );
    debug("----FIN: test_delone:ft_lstdelone----");
    return (0);

error:
    free(str_buf);
    free(lst->content);
    free(lst);
    debug("----ERR: test_delone:ft_lstdelone----");
    return (1);
}

void    del_content(void *content)
{
    free((char *)content);
}


t_list  *test_creat(void *content)
{
    debug("----RUN: test_creat:ft_lstnew----");
    t_list *created = ft_lstnew(content);

    check(
        (created != NULL),
        "1. created is NULL"
    );
    check(
        (strcmp(created->content, (char *)content) == 0),
        "2. created->content is error"
    );
    check(
        (created->next == NULL),
        "3. created->next is not NULL"
    );
    debug("----FIN: test_creat:ft_lstnew----");
    return (created);

error:
    free(created->content);
    free(created);
    debug("----ERR: test_creat:ft_lstnew----");
    return (NULL);
}
