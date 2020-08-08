#ifndef _index_h_
#define  _index_h_

#include"iostream"
#include"algorithm"

#include"string.h"
#define ElemType char


#define MaxLen 100 
using namespace std;


typedef struct {
	ElemType *data;
	int length,max ;
} SString;


bool initStr(SString &str,int len);



bool strAssign(SString &T,char * chars);

int strCompare(SString S,SString T);

int strLength(SString S);

bool subString(SString &sub,SString S,int pos,int len);

bool concat(SString &T,SString S1,SString S2);

bool strEmpty(SString s);


bool initStr(SString str);
int print_menu() ;

void printOut(SString str) ;
void choose_menu() ;
#endif
