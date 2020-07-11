#include<iostream>
#include<algorithm>
#include"string.h"
#define MaxSize 5
#define ElemType int
#define null -1


using namespace std;


typedef struct {
	int *data;
	ElemType max,length;
} SeqList;


SeqList res_null ;
#define SEQ_NULL res_null;

void enlarge_list(SeqList &list);
bool is_empty(SeqList mylist) ;
SeqList initList() ;
//输出
void print_list(SeqList t) ;
//获取数组当前长度
int get_list_length(SeqList list) ;
//获取数组容量
int get_list_max_length(SeqList list) ;

//在i位置插入e
bool insert_list(SeqList &mylist,int i,ElemType e) ;

//修改i位置的数据  修改成e
bool update_list(SeqList &mylist,int i,ElemType e) ;

//删除数据  并用e返回
bool delete_list_elem(SeqList &mylist ,int i,ElemType &e) ;


int print_menu() ;

//查找数据   -1表示没找到
int locate_elem(SeqList mylist ,ElemType e) ;

//删除最小元素
bool delete_list_min(SeqList &mylist,ElemType &e) ;


void choose_menu() ;


bool reverse_list(SeqList &mylist);

//会打乱顺序
int  delete_list_value(SeqList &mylist,ElemType e);
//不打乱顺序
int  delete_list_value_better(SeqList &mylist,ElemType e);
//不打乱顺序 s\ 
int  delete_list_value_better_too(SeqList &mylist,ElemType e);

//删除值在[a，b] 之间的所有数据
int  delete_list_by_range(SeqList &mylist,ElemType a,ElemType b);

//删除重复的值使其均不重复
int  delete_list_by_repeat(SeqList &mylist);

/*合并两个顺序表*/
SeqList emerge_list(SeqList list_a,SeqList list_b);

/* 将顺序表的0~n  和 m~最后  调换位置*/
bool reverse_list_from_ab_to_ba(SeqList &mylist,int n,int m);

//查找元素e，找到的话与后继元素交换位置，没找到就插入并使其顺序表有序
//有序顺序表
bool find_exchange_insert(SeqList &mylist ,ElemType e);

//将数组左移动space位
bool move_left(SeqList &mylist ,int space);

bool reverse_list_common(SeqList &mylist ,int from ,int to) ;

//找到 list_a和 list_b一起的中位数  并用e返回
bool find_middle_number(SeqList list_a,SeqList list_b ,ElemType &e);


bool is_mid(int now_index,int want_index ) ;

//搜索顺序表a和b 的中位数  并用e返回  better
bool M_Search(SeqList a,SeqList b ,ElemType &e) ;

//主元素 
bool find_main_elem(SeqList a,ElemType &e);

//找到最小正整数 
int find_miss_min(SeqList list);
