#include "BiLinkTree.h"

BiTree bt = NULL;

int main() {
	choose_menu();
	return 0;
}

BiTNode * find_suitable_pos(BiTree bt, ElemType tmp) {
	BiTNode *pre;
	while(bt!=NULL)
		if(bt->data>tmp) { //往右边走
			pre = bt;
			bt=bt->lchild;
		} else { //往左边走
			pre = bt;
			bt=bt->rchild;
		}
	return pre;
}

bool input_data(BiTree &bt) {
	ElemType tmp;
	BiTNode *t;
	BiTNode *p ; //临时指针
	cout<<"请输入：(输入-1结束输入)";
	cin>>tmp;
	while(tmp!=-1) {
		initTree(t);
		t->data=tmp;
		//插入
		if(bt==NULL) {//树的首个元素
			bt=t;
		} else {//找到合适的节点插入
			p=	find_suitable_pos(bt,tmp);//找到可以插入的位置的父亲节点
			if(p->data>tmp)
				p->lchild = t;
			else
				p->rchild = t;
		}
		cin>>tmp;
	}
}

//前序输出
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
	cout<<"初始化数据表请输入:1 \n";
	cout<<"退出请输入:0 \n";
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
