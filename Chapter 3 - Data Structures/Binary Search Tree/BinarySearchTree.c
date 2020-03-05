typedef struct tree {
    item_type item;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;

tree *search_tree(tree *t, item_type x) {
    if (t == NULL) {
        return NULL;
    }

    if (t -> item == x) {
        return t;
    } else if (t -> item > x) {
        return search(t -> left, x);
    } else {
        return search(t -> right, x);
    }
}