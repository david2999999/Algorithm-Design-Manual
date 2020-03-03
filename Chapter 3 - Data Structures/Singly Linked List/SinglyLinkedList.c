typedef struct list {
    item_type item;
    struct list *next;
} list;

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

//  Two C-isms to note. First, the malloc function allocates a chunk of memory
//   of sufficient size for a new node to contain x. Second, the funny double star (**l)
//   denotes that l is a pointer to a pointer to a list node. Thus the last line, *l=p;
//   copies p to the place pointed to l, which is the external variable maintaining access
//   to the head of the list.
void insert_list(list **l, item_type x) {
    list *p;
    p = malloc(sizeof(list));
    p -> item = x;
    p -> next = *l;
    *l = p;
}

list *predecessor_list(list *l, item_type x) {
    if ((l == NULL) || (l -> next == NULL)) {
        return NULL;
    }

    if ((l -> next) -> item == x) {
        return l;
    } else {
        return predecessor_list(l -> next, x);
    }
}

delete_list(list **l, item_type x) {
    list *p;
    list *pred;
    list *search_list(), *predecessor_list();

    p = search_list(*l, x);
    if (p != NULL) {
        pred = predecessor_list(*l, x);
        if (pred == NULL) {
            *l = p -> next;
        } else {
            pred -> next = p -> next;
        }

        free(p);
    }
}