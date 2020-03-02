typedef struct list {
    item_type item;
    struct list *next;
} list;

// We use *p to denote the item that is pointed to by pointer p

list *search_list(list *l, item_type x) {
    if (l == NULL) {
        return NULL;
    }

    if (l -> item == x) {
        return l;
    } else {
        return search_list(l -> next, x);
    }
}