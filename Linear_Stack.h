#ifndef Linear_Stack
#define Linear_Stack


#include"iostream"
#include"algorithm"
#include"string.h"



#define ElemType char
#define MaxSize 100

using namespace std;


typedef struct {
	ElemType *data;
	int top;
} LStack;




typedef struct {
	int *data;
	int top;
} NnumberStack;

NnumberStack nk ;

LStack sk;
string fomula ;

bool initStack(LStack &sk) ;
int print_menu() ;


void choose_menu() ;


bool isFull(LStack sk) ;

bool push(LStack &sk,ElemType x) ;
bool isEmpty(LStack sk) ;

bool pop(LStack &sk,ElemType &x) ;

bool printStack(LStack sk) ;


bool getTop(LStack sk,ElemType &x) ;

char * transferToLastTail() ;
double caculate();

#endif

