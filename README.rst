FT_S_LIST
=========

FT_S_LIST
   it's data structure for single-linked-list.
   functions of c will manipulate the data structures.
   it's part of libft project and it described as Bonus part,
   but i rather thinks to move it as datastructure.
   since, there is double linked list is also in my project.

This project creates ``ft_s_list.a`` with below specifications.

PreProcessings
--------------

.. code-block:: c

   typedef struct      s_list
   {
       void            *content;
       struct s_list   *next;
   }                   t_list;

   t_list              *ft_lstnew(void *content);
   void                ft_lstadd_front(t_list **lst, t_list *new);
   int                 ft_lstsize(t_list *lst);
   t_list              ft_lstlast(t_list *lst);
   void                ft_lstadd_back(t_list **lst, t_list *new);
   void                ft_lstdelone(t_list *lst, void (*del)(void *));
   void                ft_lstclear(t_list **lst, void (*del)(void *));
   void                ft_lstiter(t_list *lst, void (*f)(void *)); 
   t_list              *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

Functions
---------

- ``t_list            *ft_lstnew(void *content);``

   - descriptions: allocates with ``malloc`` and return new element. content initialized with content parameter, and next is to ``null``.
   - external functs: ``malloc``
   - returns: ``t_list`` created.

- ``void                ft_lstadd_front(t_list **lst, t_list *new);``

   - descriptions: Adds the element come from parameter ``new`` to beginning of ``lst``.
   - external functs: None
   - returns: None

- ``int                 ft_lstsize(t_list *lst);``

   - DESCRIPTIONS: Counts the number of elements in a list.
   - External functs: None
   - RETURNS: ``int`` count of result.

- ``t_list              ft_lstlast(t_list *lst);``
- ``void                ft_lstadd_back(t_list **lst, t_list *new);``
- ``void                ft_lstdelone(t_list *lst, void (*del)(void *));``
- ``void                ft_lstclear(t_list **lst, void (*del)(void *));``
- ``void                ft_lstiter(t_list *lst, void (*f)(void *));`` 
- ``t_list              *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));``
