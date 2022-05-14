LIB_ARRAY_STACK
---------------

SIGNATURE
^^^^^^^^^

   .. code-block:: c

      struct stack {
          size_t   siz;    // 8
          int      max;    // 8
          int      cur;    // 8 array + 24byte;
          void     *data; // ?
      };

INTERFACE
^^^^^^^^^

::
   
