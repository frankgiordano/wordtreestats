#pragma once

#include "pch.h"
#include <string.h>
#include <fstream>

extern std::ofstream fout;

extern int word_count;
extern int treeheight;
extern int left_rotate_count;
extern int right_rotate_count;

class RBTree {

public:
    RBTree();

    RBTree *Tree_Insert(RBTree *, RBTree *, RBTree *);

    RBTree *RB_Insertion(RBTree *, RBTree *);

    RBTree *Left_Rotate(RBTree *, RBTree *);

    RBTree *Right_Rotate(RBTree *, RBTree *);

    void print(RBTree *, int &);

    void Black_Height(RBTree *);

    char key[20];
    RBTree *left;
    RBTree *right;
    RBTree *parent;
    int count;
    int color;//red==1; black==2

};