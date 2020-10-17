#include <string.h>
#include <stdlib.h>
#include "s_list.h"
#include "dbg.h"

t_list *test_creat(void *content)
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
    return (0);
}

int main(void)
{
    t_list      *created;

    created = test_creat("~first created~");
    if (!created)
        exit(1);
    free(created->content);
    free(created);
    return (0);
}
