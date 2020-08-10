#ifndef _bitree_h_
#define _bitree_h_

#include "iostream"
#include "algorithm"
#include "string.h"

using namespace std;

#define ElemType char


typedef struct {
	ElemType *data;
	int childsNumer,maxNumber;
} SeqBiTree;



int print_menu() ;
void choose_menu() ;
//SeqTree
bool init_tree(SeqBiTree &sbt,int max_len);
bool init_tree_data(SeqBiTree &sbt,ElemType * data) ;
int find(SeqBiTree bt,int i,int j);





#endif
