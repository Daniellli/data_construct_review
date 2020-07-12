#ifndef _double_link_h
#define _double_link_h


#include"iostream"
#include"algorithm"

using namespace std;





#define ElemType int

typedef struct  DNode {
	ElemType data;
	struct  DNode *prior,*next;
} DNode ,*DLinkList;


int print_menu() ;

bool init_list() ;

void choose_menu() ;


bool is_empty(DLinkList ls);

bool print_all(DLinkList ls);


bool input_some_value();


DNode* get_Elem(DLinkList dls , int pos);


bool print_one(DNode * node);

bool  insert_value(DLinkList ls, int pos,ElemType v);


bool delete_node_by_pos(DLinkList ls, int pos);
#endif
