#pragma once
#include <string.h>
#include <fstream.h>

ofstream fout("result.out");

int word_count = 1;
int treeheight = 0;
int left_rotate_count = 0;
int right_rotate_count = 0;

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
	RBTree * left;
	RBTree * right;
	RBTree * parent;
	int count;
	int color;//red==1; black==2

};

