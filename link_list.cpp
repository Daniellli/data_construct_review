#include"link_list.h"


LinkList ls;
int size(LinkList ls) {

	LNode * p = ls;
	int cnt =0;
	while(p!=NULL) {
		cnt++;
		p=p->next;
	}
	return cnt;
}

bool sort(LinkList &ls) {

	if(is_empty(ls)) {
		return false;
	}
	LinkList res;

	init_list(res);

	LNode *p = ls->next,*pre;//pָ���һ���ڵ�
	LNode *r = p->next;//ָ���� �ڶ����ڵ�  ���ֲ�����
	p->next = NULL;//��һ���ڵ��̽ڵ�ȥ��  rǣ�� �����
	p = r;//ָ��ڶ���


	while(p!=NULL) {
		r=p->next;
		pre=ls;

		while( pre->next && pre->next->data < p->data)
			pre=pre->next;
		p->next = pre->next;
		pre->next=p;
		p=r;
	}
	return true;;
}

bool reverse_list(LinkList &ls) {

	if(is_empty(ls))
		return false;
	LNode *p=ls->next, *q;
	ls->next=NULL;
	while(!is_empty(p)) {
		q=p->next;//��ֹ����
		//ͷ�巨
		p->next=ls->next;
		ls->next=p;
		p=q;
	}

	return true;
}

bool delete_min_(LinkList &ls) {
	if(is_empty(ls))return false;

	LNode  *min_front = ls;
	LNode  *min_node = min_front->next,*explore,*explore_front;
//ָ��ڶ����ڵ�
	if(min_node->next!=NULL) {//�ڶ��ڵ�Ϊ��ֱ��ɾ����һ���ڵ�Ϳ�����
		//�ڶ����ڵ㲻Ϊ�� ����Ѱ����Сֵ
		explore_front = min_node;
		explore =min_node->next;
		//Ѱ����Сֵ
		while(explore!=NULL) {
			//�ҵ���Сֵ
			if(explore->data < min_node->data) {
				//�ı�min_nodeָ��
				min_front = explore_front;
				min_node= explore;
			}
			//ָ����һ��
			explore_front = explore;
			explore = explore->next;
		}
	}

	min_front->next = min_node->next;//ɾ����Сֵ
	free(min_node);
	return true;
}

void print_test_2_3_(LinkList ls) {
	if(ls->next!=NULL) {
		print_test_2_3_(ls->next);
	}
	cout<<ls->data<<"\t";
}

bool delete_node_by_pos(LinkList ls,int pos) {

	if(pos<1)
		return false;
	LNode * front_node = 	get_Elem(ls,pos-1);
	if(front_node->next==NULL) { //���������һ��Ҳ������β
		cout <<"λ�ò��Ϸ�\n";
	}  else { //ɾ���м�Ľڵ�
		LNode * t = front_node->next;
		front_node->next = t->next;
		free(t);
	}


	return true;
}


LNode * find_front_node(LinkList ls,LNode *node) {
	if(is_empty(ls) || is_empty(node))
		return NULL;

	LNode * p = ls->next;
	LNode * front  = ls;

	while(!is_empty(p)&& p != node) {
		front  = p;
		p=p->next;
	}
	return front ;
}

bool delete_node(LinkList ls,LNode* node) {

	if(is_empty(ls) || is_empty(node))
		return false;


	LinkList front_node = 	find_front_node(ls,node);
	front_node->next =node->next;
	free(node);

	return true;
}
bool insert_value(LinkList  ls , int pos,ElemType  value) {
	if(is_empty(ls))
		return false;
	if(pos<1)//����λ�ò��Ϸ�  ���������󳤶Ⱦ�Ĭ�ϲ��������һ��λ��
		return false;

	//��ʼ���½ڵ�
	LNode *tmp = (LNode *)malloc(sizeof(LNode));
	tmp->data= value ;
	LNode * p;

	p = get_Elem(ls,pos-1);//��ȡҪ����Ľڵ�ǰ���Ǹ��ڵ㣬���λ�ó�������ʵ�ʳ��ȵõ��������һ���ڵ�
	//����
	if(p) {
		tmp->next= p->next;
		p->next= tmp;
	}

	return true;
}

LNode *get_Elem_by_value(LinkList ls,ElemType v ) {

	if(is_empty(ls)) {
		return NULL;
	}

	LinkList p = ls->next;

	while(p) {
		if(p->data==v) {
			break;
		}
		p= p->next;
	}
	return p;
}
//���ص�i���ڵ�  ���i������ls�ĳ��ȷ������һ���ڵ�
LNode *get_Elem (LinkList ls,int i ) {
	int j =0;


	LinkList p = ls;

	LinkList front =NULL;

	while(!is_empty(p) &&j!=i ) {
		front= p;
		p=p->next;
		j++;
	}

	if(is_empty(p)) { //û�ҵ���i��
//		�������һ���ڵ�
		return front;
	} else
		return p;
}

void print_one(LNode *node) {
	if(!is_empty(node))
		cout<<node->data<<"\n";
}


bool input_values_without_head(LinkList &ls) {


	ElemType x;
	LNode *t,*p= ls;;
	cout<<"input :\n";

	cin>>x;

	while(x!=-1) {
		t=(LNode*)malloc(sizeof(LNode));
		t->data =x;
		if(p==NULL) { //��һ���ڵ�
			ls=t;
			t->next = NULL;
			p=t;
		} else {
			t->next = p->next;
			p->next=t;
			p=p->next;
		}
		cin>>x;
	}
}



bool init_list(LinkList &ls) {
	ls = (LinkList)malloc(sizeof(LNode));
	ls->data=0;
	ls->next= NULL;
	return true;
}


void print_wihout_head(LinkList ls) {
	LNode *p = ls;
	while(!is_empty(p)) {
		cout<<p->data<<"\t";
		p=p->next;
	}

	cout<<"\n";

}
bool print_all(LinkList ls) {
	LinkList p = ls->next;
	while(p!=NULL) {
		cout<<p->data<<"\t";
		p=p->next;
	}

	cout<<"\n";
	return true;

}

bool is_empty(LinkList ls) {
	return ls==NULL;
}
//ͷ�巨��������
bool input_some_value_from_head() {
	if(is_empty(ls))
		return false;


	LinkList p = ls;
	LNode *tmp ;
	ElemType x;
	cout<<"�����루from head��:\n";
	cin>>x;
	while(x!=-1) {
		tmp  = (LNode*)malloc(sizeof(LNode));
		tmp->data=x;
		tmp->next = p->next;
		p->next =tmp ;
		cin>>x;
	}
	return true;
}

bool input_some_value(LinkList &ls) {
	if(is_empty(ls))
		return false;
	//ָ��ͷָ��
	LinkList  p;
	p = ls;
	cout<<"������:\n";
	int x;
	LNode *tmp;
	//��ʼ����
	cin>>x;
	while(x!=-1) {//���������־
		tmp = (LNode*) malloc(sizeof(LNode));
		tmp->data=x;
		tmp->next = p->next;
		p->next = tmp;
		p=p->next;//ָ����һ��
		cin>>x;
	}
	return true;

}
int print_menu() {
	int input;
	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cout<<"��ʼ�����ݱ�������:1 \n";
	cout<<"���������:2 \n";
	cout<<"���ҽڵ�������:3 \n";
	cout<<"����ֵ���ҽڵ�:4 \n";
	cout<<"����ڵ�������:5 \n";
	cout<<"ɾ���ڵ�������:6 \n";
	cout<<"��������:7 \n";
	cout<<"2.1�� ������8\n";
	cout<<"2.2�� ������9\n";
	cout<<"2.4�� ������10\n";
	cout<<"2.5�� ������11\n";
	cout<<"sort ������12\n";

	cout<<"�˳�������:0 \n";

	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cin>>input;
	return input;
}


bool delete_value_2_2(LinkList &ls,ElemType v) {

	LNode *p = ls,*q;

	while(p->next) {

		if(p->next->data == v) {
			//ɾ���ýڵ�
			q =p->next;
			p->next = p->next->next;
			free(q);
		} else {
			p=p->next;
		}
	}

	return true;
}



void choose_menu() {
	int user_input,t1,t2,res;
	LinkList ls2=NULL;
	user_input=print_menu();
	while(user_input!=0) {
		switch(user_input) {
			case 1:
				init_list(ls);
				input_some_value_from_head();
				break;
			case 2:
				print_all(ls);
				print_test_2_3_(ls);
				cout<<"\n";
				break;
			case 3:
				cout<<"what is the rank :\n";
				cin>>t1;
				print_one(get_Elem(ls,t1));

				break;
			case 4:
				cout<<"what is the value :\n";
				cin>>t2;
				print_one(get_Elem_by_value(ls,t2));
				break;
			case 5:
				cout<<"the position you want to insert :\n";
				cin>>t1;
				cout<<"the value you want to insert :\n";
				cin>>t2;
				insert_value(ls,t1,t2);
				break;
			case 6:
				cout<<"the position you want to delete :\n";
				cin>>t1;
				delete_node_by_pos(ls,t1);
				break;
			case 7:
				cout<<size(ls)<<"\n";
				break;
			case 8:
				//2.1
				input_values_without_head(ls2);
				print_wihout_head(ls2);
				cout<<"������Ҫɾ������ֵ:\n";
				cin>>t2;
				delete_value_2_1(ls2,t2);
				cout<<"after delete:\n ";
				print_wihout_head(ls2);
				break;
			case 9:
				//2.2
				cout<<"������Ҫɾ������ֵ:\n";
				cin>>t2;
				delete_value_2_2(ls,t2);
				cout<<"after delete:\n ";
				print_all(ls);
				break;
			case 10:
				if(delete_min_(ls))
					cout<< "ɾ���ɹ�\n";
				else
					cout<<"ɾ��ʧ��\n";
				break;
			case 11:
				reverse_list(ls);
				break;
			case 12:
				sort(ls);
		}
		user_input=print_menu();
	}
}

//�ݹ�ɾ��ls�е�v
bool delete_value_2_1(LinkList &ls,ElemType v) {
	if(is_empty(ls))
		return false;
	LNode *p;
	if(ls->data == v) {
		p=ls;
		ls=ls->next;
		free(p);
		delete_value_2_1(ls,v);
	} else {
		delete_value_2_1(ls->next,v);
	}
	return true;
}


int main() {

	choose_menu();



	return 0;
}



