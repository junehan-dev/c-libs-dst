FT_S_LIST
=========

FT_S_LIST
   it's data structure for single-linked-list.
   functions of c will manipulate the data structures.
   it's part of libft project and it described as Bonus part,
   but i rather thinks to move it as datastructure.
   since, there is double linked list is also in my project.

This project creates ``ft_s_list.a`` with below specifications.

.. code-block:: bash

   make         // make all
   make test    // test and clean test.out
   make clean   // left .a file

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
   t_list              *ft_lstlast(t_list *lst);
   void                ft_lstadd_back(t_list **lst, t_list *new);
   void                ft_lstdelone(t_list *lst, void (*del)(void *));
   void                ft_lstclear(t_list **lst, void (*del)(void *));
   void                ft_lstiter(t_list *lst, void (*f)(void *)); 
   t_list              *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

Functions
---------

- ``t_list            *ft_lstnew(void *content);``

   - descriptions: allocates with ``malloc`` and return new element. content initialized with content parameter, and next is to ``null``.
   - external func: ``malloc``
   - returns: ``t_list`` created.

- ``void                ft_lstadd_front(t_list **lst, t_list *new);``

   - descriptions: Adds the element come from parameter ``new`` to beginning of ``lst``.
   - external func: None
   - returns: None

- ``int                 ft_lstsize(t_list *lst);``

   - DESCRIPTIONS: Counts the number of elements in a list.
   - External func: None
   - RETURNS: ``int`` count of result.

- ``t_list              *ft_lstlast(t_list *lst);``

   - descriptions: Point last element from lst.
   - external func: None
   - returns: ``t_list`` which next is NULL.

- ``void                ft_lstadd_back(t_list **lst, t_list *new);``

   - descriptions: Adds the element come from parameter ``new`` to end of ``lst``.
   - external func: None
   - returns: None

- ``void                ft_lstdelone(t_list *lst, void (*del)(void *));``

   - descriptions: argument lst is target element to free. ``del`` is function pointer used to delete content of the element. next must not be freed.
   - external func: ``free``
   - returns: None

- ``void                ft_lstclear(t_list **lst, void (*del)(void *));``

   - descriptions: Deletes and frees given element and every successors of that element. the pointer to a list must be set to NULL at last.
   - external func: ``free``
   - returns: None

- ``void                ft_lstiter(t_list *lst, void (*f)(void *));`` 

   - descriptions: Deletes and frees given element and every successors of that element. the pointer to a list must be set to NULL at last.
   - external func: ``free``
   - returns: None

- ``t_list              *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));``

   - descriptions: iterates function ``f`` to each content to lst. and if needed ``del`` is used to delete content.
   - external func: ``malloc`` ``free``
   - returns: malloc fail on ``NULL`` or ``lst``
