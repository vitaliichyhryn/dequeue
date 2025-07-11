#include "list.h"
#include <assert.h>
#include <stdlib.h>

int main()
{
    struct list *list;
    list_init(&list);

    int foo = 5;
    int bar = 10;
    list_push_front(list, &foo);
    list_push_front(list, &bar);

    int *got_bar;
    list_pop_front(list, (void **)&got_bar);
    assert(*got_bar == bar);

    int *got_foo;
    list_pop_front(list, (void **)&got_foo);
    assert(*got_foo == foo);

    return EXIT_SUCCESS;
}
