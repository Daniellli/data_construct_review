#ifndef static_list_h_
#define static_list_h_
#include"iostream"
#include"algorithm"
#include"string.h"

#define ElemType int



#define MaxSize 50


using namespace std;



typedef struct {
	ElemType data;
	int next;
} SNode,*SLinkList;

typedef struct{
	SLinkList data;
	int max,length,head;
}d,*SSLinkList;


int print_menu() ;

bool input_some_value();

bool init_list() ;

void choose_menu() ;

bool is_empty(SLinkList ls);

bool print_all();

#endif


