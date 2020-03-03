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