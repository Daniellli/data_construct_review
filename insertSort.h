#ifndef _insert_sort_h
#define _insert_sort_h


#include "iostream"
#include "algorithm"

#include<ctime>

using namespace std;


typedef int ElemType ;


void print(ElemType *A,int len) ;
void initial(ElemType *data ,int len) ;

void insert_sort(ElemType *A,int len);


void insert_middle_sort(ElemType *A , int len) ;

void ShellSort(ElemType *A , int len) ;


void quickSort(ElemType *A ,int low,int high) ;

int partition(ElemType *A ,int low,int high) ;



//√∞≈›≈≈–Ú
void bubbleSort(ElemType *A , int len) ;

void choosingSort(ElemType *A , int n) ;
#endif
