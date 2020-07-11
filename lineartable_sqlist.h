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
//���
void print_list(SeqList t) ;
//��ȡ���鵱ǰ����
int get_list_length(SeqList list) ;
//��ȡ��������
int get_list_max_length(SeqList list) ;

//��iλ�ò���e
bool insert_list(SeqList &mylist,int i,ElemType e) ;

//�޸�iλ�õ�����  �޸ĳ�e
bool update_list(SeqList &mylist,int i,ElemType e) ;

//ɾ������  ����e����
bool delete_list_elem(SeqList &mylist ,int i,ElemType &e) ;


int print_menu() ;

//��������   -1��ʾû�ҵ�
int locate_elem(SeqList mylist ,ElemType e) ;

//ɾ����СԪ��
bool delete_list_min(SeqList &mylist,ElemType &e) ;


void choose_menu() ;


bool reverse_list(SeqList &mylist);

//�����˳��
int  delete_list_value(SeqList &mylist,ElemType e);
//������˳��
int  delete_list_value_better(SeqList &mylist,ElemType e);
//������˳�� s\ 
int  delete_list_value_better_too(SeqList &mylist,ElemType e);

//ɾ��ֵ��[a��b] ֮�����������
int  delete_list_by_range(SeqList &mylist,ElemType a,ElemType b);

//ɾ���ظ���ֵʹ������ظ�
int  delete_list_by_repeat(SeqList &mylist);

/*�ϲ�����˳���*/
SeqList emerge_list(SeqList list_a,SeqList list_b);

/* ��˳����0~n  �� m~���  ����λ��*/
bool reverse_list_from_ab_to_ba(SeqList &mylist,int n,int m);

//����Ԫ��e���ҵ��Ļ�����Ԫ�ؽ���λ�ã�û�ҵ��Ͳ��벢ʹ��˳�������
//����˳���
bool find_exchange_insert(SeqList &mylist ,ElemType e);

//���������ƶ�spaceλ
bool move_left(SeqList &mylist ,int space);

bool reverse_list_common(SeqList &mylist ,int from ,int to) ;

//�ҵ� list_a�� list_bһ�����λ��  ����e����
bool find_middle_number(SeqList list_a,SeqList list_b ,ElemType &e);


bool is_mid(int now_index,int want_index ) ;

//����˳���a��b ����λ��  ����e����  better
bool M_Search(SeqList a,SeqList b ,ElemType &e) ;

//��Ԫ�� 
bool find_main_elem(SeqList a,ElemType &e);

//�ҵ���С������ 
int find_miss_min(SeqList list);
