#include <stdlib.h>
#include "list.h"

const struct list_err LIST_OK = { LIST_ERR_CODE_OK, ""};
const struct list_err LIST_ERR_NULLPTR = { LIST_ERR_CODE_NULLPTR, "null pointer dereference"};
const struct list_err LIST_ERR_ALLOC = { LIST_ERR_CODE_ALLOC, "couldn't allocate memory"};
const struct list_err LIST_ERR_EMPTY = { LIST_ERR_CODE_EMPTY, "list is empty"};

struct list_err list_init(struct list **self) {
    *self = malloc(sizeof(struct list));
    if (*self == nullptr) {
        return LIST_ERR_ALLOC;
    }
    **self = (struct list){ .front = nullptr, .back = nullptr };
    return LIST_OK;
}

struct list_err node_init(struct node **self, void *elem) {
    *self = malloc(sizeof(struct node));
    if (*self == nullptr) {
        return LIST_ERR_ALLOC;
    }
    **self = (struct node){ .elem = elem, .front = nullptr, .back = nullptr };
    return LIST_OK;
}

struct list_err list_push_front(struct list *self, void *elem) {
    if (self == nullptr) {
        return LIST_ERR_NULLPTR;
    }
    struct node *new_front;
    auto err = node_init(&new_front, elem);
    if (err.code != LIST_ERR_CODE_OK) {
        return err;
    }

    if (self->front == nullptr) {
        self->back = new_front;
    } else {
        new_front->back = self->front;
        self->front->front = new_front;
    }
    self->front = new_front;
    return LIST_OK;
}

struct list_err list_pop_front(struct list *self, void **elem) {
    if (self == nullptr) {
        return LIST_ERR_NULLPTR;
    }
    if (self->front == nullptr) {
        return LIST_ERR_EMPTY;
    }
    *elem = self->front->elem;
    auto old_front = self->front;
    if (self->front == self->back) {
        self->back = nullptr;
    }
    self->front = self->front->back;
    if (self->front != nullptr) {
        self->front->front = nullptr;
    }
    free(old_front);
    return LIST_OK;
}

