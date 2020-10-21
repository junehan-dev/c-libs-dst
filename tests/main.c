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
void    test_addback(const char *content);
void    test_map(t_list *lst, void *(*f)(void *), void (*del)(void *));


int main(void)
{
    t_list      *created;
    t_list      *end;
    const char  *contents[4] = {"1str", "2str", "3str", NULL};

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

    test_lstiter(created);
    test_lstsize(created, 3);
    
    test_lstclear(contents);
//    test_addback("back added string");
//    test_map

    debug("TEST END---------");
    return (0);
}

int    test_lstclear(const char **contents)
{
    int         i;
    t_list      **lst_arr;
    char        *content_pt[10] = { NULL };

    i = 0;
    debug("----RUN: test_clear:ft_lstclear----");
    while (*(contents + i))
        i++;
    
    lst_arr = (t_list **)malloc(sizeof(t_list) * (i + 1));
    *(lst_arr + i) = NULL;

    while (i--)
    {
        *(lst_arr + i) = ft_lstnew((void *)(*(contents + i)));
        check(
            (strcmp(
                (char *)((*(lst_arr + i))->content), *(contents+i)) == 0
            ),
            "created content and insert non equal!"
        );
        debug("created->content: '%s' '%s':input", 
        (char *)((*(lst_arr + i))->content), *(contents + i)
        );
        *(content_pt + i) = ((char *)((*(lst_arr + i))->content));
        debug("ptcopied : %s, %p == %p", 
            *(content_pt + i),
            *(content_pt + i),
            (*(lst_arr + i))->content
        );
    }

    i = 3;
    ft_lstclear(lst_arr, del_content);
    while (i--) 
        debug("%d str: %s", i, *(content_pt + i));
        check(
            strcmp(*(content_pt + i), *(contents+i)) != 0,
            "string is no diff!"
        );
    check(sizeof(*lst_arr) != sizeof(t_list), "freed error");
    debug("----FIN: test_clear:ft_lstclear----");
    return (0);
    
error:
    i = 3;
    while(i--)
        ft_lstdelone(*(lst_arr + i), del_content);

    free(lst_arr);
    debug("----ERR: test_clear:ft_lstclear----");
    return 1;
}


/*
void    test_addback(const char *content)
{
    t_list **lstarr;

    lstarr = malloc(sizeof(t_list) * 4);
    *(lstarr + 3) = NULL;
    *(lstarr + 1

}
*/

/*
void    test_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list ret;

    ret = ft_lstmap(lst, f, del);
}
*/

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

    while (cur->next)
    {
        free(cur);
        cur = next;
        next = cur->next;
    }
    free(cur);

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
