#include "BiLinkTree.h"

#define stack_max_len 50
#define queue_max_len 50


BiTree bt = NULL;
TreeStack stack;
TreeQueue  queue;
int main() {
	choose_menu();
	return 0;
}

//������ȱ���
void broadRecursion(BiTree bt) {
	BiTNode *p ;
	initQueue(queue);
	enque(queue,bt);
	
	while(!isQueEmpty(queue)) {
		deque(queue,p);
		visit(p);
		if(p->lchild!=NULL)
			enque(queue,p->lchild);
		if(p->rchild!=NULL)
			enque(queue,p->rchild);
	}
	clear(queue);//�ͷ��ڴ�ռ�

}

void clear(TreeQueue que) {
	free(que.data);
}

//��ʼ������
bool initQueue(TreeQueue &que) {
	que.data = (BiTree *)malloc(sizeof(BiTree)*queue_max_len);
	que.front = que.rear = 0;
}

bool enque(TreeQueue &queue,BiTree p) {
	if(isQueFull(queue))return false;
	queue.data[queue.rear] = p;
	queue.rear = (queue.rear+1)%queue_max_len;
	return true;
}

bool deque(TreeQueue &queue,BiTree &p) {
	if(isQueEmpty(queue))return false;
	p = queue.data[queue.front];
	queue.front = (queue.front+1) %queue_max_len;
	return true;
}

bool isQueEmpty(TreeQueue que) {
	return  que.rear == que.front;
}

bool isQueFull(TreeQueue que) {
	return (que.rear+1)%queue_max_len == que.front;
}



void inOrderWithRecursion(BiTree bt) {
	BiTNode *p = bt;
	initStack(stack);
	while(p ||!isEmpty(stack)) {
		if(p) {
			push(stack,p);
			p=p->lchild;
		} else {
			popup(stack,p)	;
			cout<<p->data<<"\t";
			p=p->rchild;
		}
	}
}




bool isEmpty(TreeStack stack) {
	return stack.top==-1;
}

void initStack(TreeStack &stack) {
	stack.data=(BiTree *)malloc(sizeof(BiTree)*stack_max_len);
	stack.top=-1;
}

bool popup(TreeStack &stack,BiTree &p) {
	if(stack.top==-1)return false;
	p=stack.data[stack.top--] ;
	return true;
}

bool push(TreeStack &stack,BiTree p) {
	if(stack.top+1 ==stack_max_len)return false;
	stack.data[++stack.top] = p;
	return true;
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
		visit(bt);
		preOrder(bt->lchild);
		preOrder(bt->rchild);
	}
}
void visit(BiTree bt) {
	cout<<bt->data<<"\t";
}

void inOrder(BiTree bt) {

	if(bt!=NULL) {
		inOrder(bt->lchild);
		visit(bt);
		inOrder(bt->rchild);
	}
}


void postOrder(BiTree bt) {
	if(bt!=NULL) {
		postOrder(bt->lchild);
		postOrder(bt->rchild);
		visit(bt);
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
	cout<<"ǰ�����������:2 \n";
	cout<<"�������������:3 \n";
	cout<<"�������������:4 \n";
	cout<<"�ǵݹ��������������:5 \n";
	cout<<"������ȱ��� ������6\n" ;
	
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
				cout<<"\n";
				break;
			case 3:
				inOrder(bt);
				cout<<"\n";
				break;
			case 4:
				postOrder(bt);
				cout<<"\n";
				break;
			case 5:
				inOrderWithRecursion(bt);
				cout<<"\n";
				break;
			case 6:
				broadRecursion(bt);
				cout<<"\n";
				break;

		}
		user_input=print_menu();
	}
}
