#include <string.h>
#include <stdlib.h>
#include "s_list.h"
#include "dbg.h"

t_list  *test_creat(void *content);
int     test_delone(t_list *lst);
void    del_content(void *);

int main(void)
{
    t_list      *created;

    debug("TEST START---------");

    created = test_creat("~first created~");
    if (!created)
        exit(1);
    if(test_delone(created) == 1)
        exit(1);

    debug("TEST END---------");
    return (0);
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
