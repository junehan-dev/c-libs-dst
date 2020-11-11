#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "s_list.h"
#include "dbg.h"

t_list  *test_creat(void *content);
int     test_delone(t_list *lst);
void    del_content(void *);
int     test_lstsize(t_list *lst, size_t size);
void    test_lstiter(t_list *lst);
void    to_upper(void *);
int     test_lstclear(const char **contents);
int     test_lstadd_back(t_list **lst, const char *content);
int    test_lstmap(t_list **lst, void *(*f)(void *), void (*del)(void *));
void    *map_f(void *content);

int main(void)
{
    t_list      *created;

    debug("TEST START---------");

    created = test_creat("~first created~");
    if (!created)
        exit(1);
    if(test_delone(created) == 1)
        exit(1);

    created = ft_lstnew("1lst_start");
    ft_lstadd_back(&created, ft_lstnew("2lst_2"));
    ft_lstadd_back(&created, ft_lstnew("3lst_3"));

    test_lstiter(created);
    test_lstsize(created, 3);
    debug("created: %s", (char *)(created->content));
    test_lstadd_back(&created, "back added string");
    test_lstadd_back(&created, "back added string 2");

    test_lstsize(created, 5);
    test_lstmap(&created, map_f, del_content);
    debug("TEST END---------");
    return (0);
}

int     test_lstadd_back(t_list **lst, const char *content)
{
    t_list      *to_add;
    t_list      *lst_pt;
    int         i;

    debug("----RUN: test_lstadd_back:ft_lstadd_back----");
    lst_pt = *lst;
    to_add = ft_lstnew((void *)content);
    ft_lstadd_back(lst, to_add);
    i = 0;

    debug("first string :%s", (char *)((*lst)->content));
    debug("toadd string :%s", (char *)(to_add->content));
    while (lst_pt != to_add && lst_pt != NULL)
    {
        if ((char *)(lst_pt->content) != NULL)
            debug("%d->content: '%s'", i, (char *)(lst_pt->content));
        else
            debug("%d->content: NULL", i);
        lst_pt= lst_pt->next;
        i++;
    }

    debug("%d->content: '%s'", i, (char *)(lst_pt->content));
    check(lst_pt == to_add, "not added.");
    check(lst_pt->next == NULL, "not added to back");
    debug("----FIN: test_lstadd_back:ft_lstadd_back----");
    return (0);

error:
    debug("----ERR: test_lstadd_back:ft_lstadd_back----");
    return (1);
}

int    test_lstclear(const char **contents)
{
    int         i;
    char        *content_pt[10] = {NULL};
    t_list      *lst; 
    t_list      *lst_pt;

    i = 0;
    debug("----RUN: test_clear:ft_lstclear----");
    lst = ft_lstnew((void *)*contents);
    lst_pt = lst;
    
    while (*(contents + i))
    {
        ft_lstadd_back(&lst, ft_lstnew((void *)(*(contents+i))));
        debug("%d : %s:%s" , i, *(contents+i), (char *)lst_pt->content);
        lst_pt = lst_pt->next;
        i++;
    }
    
    i = 0;
    lst_pt = lst;
    while (i < 3)
    {
        debug("%s == %s",
                (const char *)(lst_pt->content), *(contents + i));
        check(
            (strcmp(
                (char *)(lst_pt->content), *(contents + i)) == 0
            ),
            "created content and insert non equal!"
        );
        debug("created->content: '%s' '%s':input", 
            (char *)(lst_pt ->content), *(contents + i)
        );
        *(content_pt + i) = ((char *)(lst_pt->content));
        debug("ptcopied : %s, %p == %p", 
            *(content_pt + i),
            *(content_pt + i),
            (lst_pt->content)
        );
        lst_pt = lst_pt->next;
        debug("next:%s", (char *)lst_pt->content);
        i++;
    }

    i = 0;
    ft_lstclear(&lst, del_content);
    while (*(content_pt + i)) 
    {
        debug("%d str: %s", i, *(content_pt + i));
        check(!(contents+i),
            "string is NOT NULL!"
        );
        i++;
    }
    check(!(lst), "freed error");
    debug("----FIN: test_clear:ft_lstclear----");
    return (0);
    
error:
    ft_lstclear(&lst, del_content);
    debug("----ERR: test_clear:ft_lstclear----");
    return 1;
}

int    test_lstmap(t_list **lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *ret;
    t_list *ret_pt;

    char *keys[4] = {"1LST_START", "2LST_2\0", "3LST_3\0", NULL};
    int i;

    i = 0;
    debug("----RUN: test_map:ft_lstmap----");
    ret = ft_lstmap(*lst, f, del);
    debug("%s", (char *)ret->content);
    debug("%s", (char *)(ret->next)->content);
    ret_pt = ret;
    
    while (i<3)
    {
        debug("%d: '%s|%s'", i, (const char*)(ret_pt->content), (const char *)(keys[i]));
        check(strcmp((const char*)(ret_pt->content), (const char *)(keys[i])) == 0,
            "result non equal"
        );
        ret_pt = ret_pt->next;
        i++;
    }
    debug("----FIN: test_map:ft_lstmap----");
    ft_lstclear(&ret, del_content);
    check(ret_pt == NULL, "non null!");
    return (EXIT_SUCCESS);
error:
    debug("%d: %s|%s", i, (const char*)(ret_pt->content), (const char *)(keys[i]));
    debug("%d", strcmp((const char*)(ret_pt->content), (const char *)(keys[i])));
    debug("----ERR: test_map:ft_lstmap----");
    ft_lstclear(&ret, del_content);
    return (EXIT_FAILURE);

}

void    to_upper(void *content)
{
    char *str;

    str = (char *)content;
    while (*str)
    {
        if (isalpha(*str) && islower(*str))
            *str = toupper(*str);
        str++;
    }
    debug("uppered string: %s", (char *)content);
}

void     check_upper(void *content)
{
    char    *str;
    int     i;

    i = 0;
    str = (char *)content;
    debug("check upper: %s", str);
    while (*str)
    {
        if (isalpha(*str))
        {
            check(
                (isupper(*str) != 0),
                "1. iter not chaged content to upper"
            );
        }
        i++;
        str++;
    }
    debug("----FIN: test_iter:ft_lstiter----");
    return;

error:
    debug("%d:'%c' is not upper!", i, *str);
}


void test_lstiter(t_list *lst)
{
    debug("----RUN: test_iter:ft_lstiter----");
    ft_lstiter(lst, to_upper);
    ft_lstiter(lst, check_upper);
}

int test_lstsize(t_list *lst, size_t size)
{
    int     ret;

    debug("----RUN: test_size:ft_lstsize----");
    ret = ft_lstsize(lst);
    check(
        ((size_t)ret == size),
        "1. t_list length non equal."
    );
    debug("----FIN: test_size:ft_lstsize----");

    return (0);

error:
    debug("expected: %ld, actual: %d", size, ret);
    debug("----ERR: test_size:ft_lstsize----");

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
    debug("del: -%s-", (char *)content);
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

void    *map_f(void *content)
{
    const char    *content_pt;

    if (content)
    {
        content_pt = (const char *)content;
        debug("map_f:%c", *content_pt);
        if ('0' <= *content_pt && '4' >= *content_pt)
        {
            debug("passed: %s", content_pt);
            return content;
        }
    }
    return (NULL);

}
