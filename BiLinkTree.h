#ifndef _bi_link_tree_h_
#define _bi_link_tree_h_
#include "iostream"
#include "algorithm"
#include "string.h"

using namespace std;

#define ElemType int


typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;


int print_menu();
void choose_menu() ;
//Link Tree
void initTree(BiTree &bt) ;




#endif
