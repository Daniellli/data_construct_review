#include "BiLinkTree.h"

BiTree bt = NULL;

int main() {
	choose_menu();
	return 0;
}

BiTNode * find_suitable_pos(BiTree bt, ElemType tmp) {
	BiTNode *pre;
	while(bt!=NULL)
		if(bt->data>tmp) { //���ұ���
			pre = bt;
			bt=bt->lchild;
		} else { //�������
			pre = bt;
			bt=bt->rchild;
		}
	return pre;
}

bool input_data(BiTree &bt) {
	ElemType tmp;
	BiTNode *t;
	BiTNode *p ; //��ʱָ��
	cout<<"�����룺(����-1��������)";
	cin>>tmp;
	while(tmp!=-1) {
		initTree(t);
		t->data=tmp;
		//����
		if(bt==NULL) {//�����׸�Ԫ��
			bt=t;
		} else {//�ҵ����ʵĽڵ����
			p=	find_suitable_pos(bt,tmp);//�ҵ����Բ����λ�õĸ��׽ڵ�
			if(p->data>tmp)
				p->lchild = t;
			else
				p->rchild = t;
		}
		cin>>tmp;
	}
}

//ǰ�����
void preOrder(BiTree bt) {
	if(bt!=NULL) {
		cout<<bt->data<<"\t";
		preOrder(bt->lchild);
		preOrder(bt->rchild);
	}
}

void initTree(BiTree &bt) {
	bt = (BiTNode *)malloc(sizeof(BiTNode));
	bt->data =0;
	bt->lchild=bt->rchild=NULL;
}



int print_menu() {
	int input;
	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cout<<"��ʼ�����ݱ�������:1 \n";
	cout<<"�˳�������:0 \n";
	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cin>>input;
	return input;
}


void choose_menu() {

	int user_input,t1,t2,res;
	ElemType *t;
	user_input=print_menu();
	while(user_input!=0) {
		switch(user_input) {
			case 1:
				input_data(bt);
				break;
			case 2:
				preOrder(bt);
				break;


		}
		user_input=print_menu();
	}
}
