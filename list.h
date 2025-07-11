#pragma once

enum list_err_code {
    LIST_ERR_CODE_OK,
    LIST_ERR_CODE_NULLPTR,
    LIST_ERR_CODE_ALLOC,
    LIST_ERR_CODE_EMPTY,
};

struct list_err {
    enum list_err_code code;
    const char *str;
};

extern const struct list_err LIST_OK;
extern const struct list_err LIST_ERR_NULLPTR;
extern const struct list_err LIST_ERR_ALLOC;
extern const struct list_err LIST_ERR_EMPTY;

struct node {
    struct node* front;
    struct node* back;
    void *elem;
};

struct list {
    struct node *front;
    struct node *back;
};

struct list_err list_init(struct list **self);
struct list_err node_init(struct node **self, void *elem);
struct list_err list_push_front(struct list *self, void *elem);
struct list_err list_pop_front(struct list *self, void **elem);
