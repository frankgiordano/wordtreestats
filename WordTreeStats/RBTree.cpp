#include "RBTree.h"

RBTree::RBTree() {
    left = 0;
    right = 0;
    parent = 0;
    count = 1;
}

RBTree *RBTree::Tree_Insert(RBTree *t, RBTree *y, RBTree *z) {
    if (t == 0) {
        t = z;
        t->parent = y;
        word_count++;
    } else if (strcmp(z->key, t->key) < 0) {
        t->left = Tree_Insert(t->left, t, z);
    } else if (strcmp(z->key, t->key) > 0) {
        t->right = Tree_Insert(t->right, t, z);
    } else if (strcmp(z->key, t->key) == 0) {
        t->count++;
    }

    return t;
}

RBTree *RBTree::RB_Insertion(RBTree *t, RBTree *x) {
    RBTree *y;

    t = Tree_Insert(t, 0, x);
    x->color = 1;
    while ((x->parent != 0) && (x->parent->parent != 0) && (x != t) && (x->parent->color == 1)) {
        if ((x->parent == x->parent->parent->left)) {
            y = x->parent->parent->right;
            if ((y != 0) && (y->color == 1)) {
                x->parent->color = 2;
                y->color = 2;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            } else {
                if (x == x->parent->right) {
                    x = x->parent;
                    t = Left_Rotate(t, x);
                }
                x->parent->color = 2;
                x->parent->parent->color = 1;
                t = Right_Rotate(t, x->parent->parent);
            }
        } else {
            y = x->parent->parent->left;
            if ((y != 0) && (y->color == 1)) {
                x->parent->color = 2;
                y->color = 2;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            } else {
                if (x == x->parent->left) {
                    x = x->parent;
                    t = Right_Rotate(t, x);
                }
                x->parent->color = 2;
                x->parent->parent->color = 1;
                t = Left_Rotate(t, x->parent->parent);
            }
        }

    }

    t->color = 2;
    return t;
}

RBTree *RBTree::Left_Rotate(RBTree *t, RBTree *x) {
    left_rotate_count++;
    RBTree *y;

    y = x->right;
    x->right = y->left;

    if (y->left != 0)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == 0)
        t = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else x->parent->right = y;

    y->left = x;
    if (x != 0)
        x->parent = y;

    return t;
}

RBTree *RBTree::Right_Rotate(RBTree *t, RBTree *x) {
    right_rotate_count++;
    RBTree *y;
    y = x->left;
    x->left = y->right;

    if (y->right != 0)
        y->right->parent = x;

    y->parent = x->parent;
    if (x->parent == 0)
        t = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else x->parent->left = y;

    y->right = x;

    if (x != 0)
        x->parent = y;

    return t;
}

void RBTree::Black_Height(RBTree *t) {
    int height = 0;

    while (t->right != 0) {
        t = t->right;
        if (t->color == 2) height++;
    }

    height++;
    fout << height << " - black tree height" << std::endl;
}

void RBTree::print(RBTree *t, int &height) {
    int left_height = 0, right_height = 0;
    int static count;

    if (t == 0)
        return;

    print(t->left, left_height);
    count++;
    fout << t->key << " " << t->count << "  ";

    if (count == 1) {
        fout << std::endl;
        count = 0;
    }

    print(t->right, right_height);
    height = left_height > right_height ? height = left_height + 1 : height = right_height + 1;
    return;
}
