#ifndef _index_h_
#define  _index_h_

#include"iostream"
#include"algorithm"

#include"string.h"
#define ElemType char

using namespace std;


typedef struct {
	ElemType *data;
	int length,max ;
} SString;


SString str;
bool initStr(SString &str,int len);


bool initStr(SString str);
int print_menu() ;

void printOut(SString str) ;
void choose_menu() ;
#endif
