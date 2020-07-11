#ifndef LINK_LIST_H
#define LINK_LIST_H
#include"iostream"
#include"algorithm"
#include"string.h"

#define ElemType int


using namespace std;


typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode,*LinkList;



int print_menu() ;
bool input_some_value();

bool input_some_value_from_head();


bool init_list() ;


void choose_menu() ;

bool is_empty(LinkList ls);

bool print_all();

LNode *get_Elem (LinkList ls,int i );

LNode *get_Elem_by_value(LinkList ls,ElemType v );

bool insert_value(LinkList  ls , int pos,ElemType  value);

bool delete_node(LinkList ls,LNode* node);

bool delete_node_by_pos(LinkList ls,int pos);


LNode * find_front_node(LinkList ls,LNode *node) ;
void print_one(LNode *node);




int size(LinkList ls);
#endif


