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


typedef struct {
	BiTree *data;
	int top;
} TreeStack;

typedef struct {
	BiTree *data;
	int front,rear;
} TreeQueue;


int print_menu();
void choose_menu() ;
//Link Tree
void initTree(BiTree &bt) ;


void visit(BiTree bt) ;
void inOrder(BiTree bt) ;
void postOrder(BiTree bt) ;

void inOrderWithRecursion(BiTree bt) ;
//stack
void initStack(TreeStack &stack) ;
bool push(TreeStack &stack,BiTree p) ;
bool popup(TreeStack &stack,BiTree &p) ;
bool isEmpty(TreeStack stack) ;
//queue
//初始化队列
bool initQueue(TreeQueue &que) ;

bool enque(TreeQueue &queue,BiTree p) ;

bool deque(TreeQueue &queue,BiTree &p) ;

bool isQueEmpty(TreeQueue que) ;

bool isQueFull(TreeQueue que) ;	
void clear(TreeQueue que) ; 
#endif
