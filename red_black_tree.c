#include <stdio.h>
#include <stdlib.h>

enum color { RED, BLACK };

struct Node {
    enum color colour;
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* root = NULL;

/* Function prototypes */
void case1(struct Node *n);
void case2(struct Node *n);
void case3(struct Node *n);
void case4(struct Node *n);
void case5(struct Node *n);

void rotate_left(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rotate_right(struct Node* x) {
    struct Node* y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}

struct Node* grandparent(struct Node* n) {
    return (n && n->parent) ? n->parent->parent : NULL;
}

struct Node* uncle(struct Node* n) {
    struct Node* g = grandparent(n);
    if (!g) return NULL;
    return (n->parent == g->left) ? g->right : g->left;
}

/* Fix-up cases */

void case1(struct Node* n) {
    if (n->parent == NULL)
        n->colour = BLACK;
    else
        case2(n);
}

void case2(struct Node* n) {
    if (n->parent->colour == BLACK)
        return;
    else
        case3(n);
}

void case3(struct Node* n) {
    struct Node* u = uncle(n);
    struct Node* g = grandparent(n);

    if (u && u->colour == RED) {
        n->parent->colour = BLACK;
        u->colour = BLACK;
        g->colour = RED;
        case1(g);
    } else {
        case4(n);
    }
}

void case4(struct Node* n) {
    struct Node* g = grandparent(n);

    if (n == n->parent->right && n->parent == g->left) {
        rotate_left(n->parent);
        n = n->left;
    } else if (n == n->parent->left && n->parent == g->right) {
        rotate_right(n->parent);
        n = n->right;
    }
    case5(n);
}

void case5(struct Node* n) {
    struct Node* g = grandparent(n);

    n->parent->colour = BLACK;
    g->colour = RED;

    if (n == n->parent->left && n->parent == g->left)
        rotate_right(g);
    else
        rotate_left(g);
}

/* Insert helpers */

struct Node* create_node(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->colour = RED;
    n->left = n->right = n->parent = NULL;
    return n;
}

void bst_insert(struct Node* current, struct Node* n) {
    if (n->data < current->data) {
        if (current->left)
            bst_insert(current->left, n);
        else {
            current->left = n;
            n->parent = current;
        }
    } else {
        if (current->right)
            bst_insert(current->right, n);
        else {
            current->right = n;
            n->parent = current;
        }
    }
}

void rb_insert(int data) {
    struct Node* n = create_node(data);

    if (root == NULL) {
        root = n;
    } else {
        bst_insert(root, n);
    }
    case1(n);
}

void inorder(struct Node* n) {
    if (!n) return;
    inorder(n->left);
    printf("%d(%s) ", n->data, n->colour == RED ? "R" : "B");
    inorder(n->right);
}

int main() {
    int values[] = {10, 20, 30, 15, 25, 5};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        rb_insert(values[i]);

    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    return 0;
}
