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

tree *find_minimum(tree *t) {
    tree *min;

    if (t == NULL) {
        return NULL;
    }

    min = t;
    while (min -> left != NULL) {
        min = min -> left;
    }

    return min;
}

void inorder_traverse_tree(tree *t) {
    if (t != NULL) {
        inorder_traverse_tree(t -> left);
        process_item(t -> item);
        inorder_traverse_tree(t -> right);
    }
}

void preorder_traverse_tree(tree *t) {
    if (t != NULL) {
        process_item(t -> item);
        preorder_traverse_tree(t -> left);
        preorder_traverse_tree(t -> right);
    }
}

void postorder_traverse_tree(tree *t) {
    if (t != NULL) {
        postorder_traverse_tree(t -> right);
        postorder_traverse_tree(t -> left);
        process_item(t -> item);
    }
}