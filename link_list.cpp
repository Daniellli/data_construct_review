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

	LNode *p = ls->next,*pre;//p指向第一个节点
	LNode *r = p->next;//指向后继 第二个节点  保持不断链
	p->next = NULL;//第一个节点后继节点去掉  r牵着 不会断
	p = r;//指向第二个


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
		q=p->next;//防止断链
		//头插法
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
//指向第二个节点
	if(min_node->next!=NULL) {//第二节点为空直接删除第一个节点就可以了
		//第二个节点不为空 遍历寻找最小值
		explore_front = min_node;
		explore =min_node->next;
		//寻找最小值
		while(explore!=NULL) {
			//找到更小值
			if(explore->data < min_node->data) {
				//改变min_node指向
				min_front = explore_front;
				min_node= explore;
			}
			//指向下一个
			explore_front = explore;
			explore = explore->next;
		}
	}

	min_front->next = min_node->next;//删除最小值
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
	if(front_node->next==NULL) { //返回了最后一个也就是链尾
		cout <<"位置不合法\n";
	}  else { //删除中间的节点
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
	if(pos<1)//插入位置不合法  如果超过最大长度就默认插入在最后一个位置
		return false;

	//初始化新节点
	LNode *tmp = (LNode *)malloc(sizeof(LNode));
	tmp->data= value ;
	LNode * p;

	p = get_Elem(ls,pos-1);//获取要插入的节点前面那个节点，如果位置超过链表实际长度得到的是最后一个节点
	//插入
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
//返回第i个节点  如果i超过了ls的长度返回最后一个节点
LNode *get_Elem (LinkList ls,int i ) {
	int j =0;


	LinkList p = ls;

	LinkList front =NULL;

	while(!is_empty(p) &&j!=i ) {
		front= p;
		p=p->next;
		j++;
	}

	if(is_empty(p)) { //没找到第i个
//		返回最后一个节点
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
		if(p==NULL) { //第一个节点
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
//头插法插入数据
bool input_some_value_from_head() {
	if(is_empty(ls))
		return false;


	LinkList p = ls;
	LNode *tmp ;
	ElemType x;
	cout<<"请输入（from head）:\n";
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
	//指向头指针
	LinkList  p;
	p = ls;
	cout<<"请输入:\n";
	int x;
	LNode *tmp;
	//开始输入
	cin>>x;
	while(x!=-1) {//输入结束标志
		tmp = (LNode*) malloc(sizeof(LNode));
		tmp->data=x;
		tmp->next = p->next;
		p->next = tmp;
		p=p->next;//指向下一个
		cin>>x;
	}
	return true;

}
int print_menu() {
	int input;
	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cout<<"初始化数据表请输入:1 \n";
	cout<<"输出请输入:2 \n";
	cout<<"查找节点请输入:3 \n";
	cout<<"根据值查找节点:4 \n";
	cout<<"插入节点请输入:5 \n";
	cout<<"删除节点请输入:6 \n";
	cout<<"表长请输入:7 \n";
	cout<<"2.1题 请输入8\n";
	cout<<"2.2题 请输入9\n";
	cout<<"2.4题 请输入10\n";
	cout<<"2.5题 请输入11\n";
	cout<<"sort 请输入12\n";

	cout<<"退出请输入:0 \n";

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
			//删除该节点
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
				cout<<"请输入要删除的数值:\n";
				cin>>t2;
				delete_value_2_1(ls2,t2);
				cout<<"after delete:\n ";
				print_wihout_head(ls2);
				break;
			case 9:
				//2.2
				cout<<"请输入要删除的数值:\n";
				cin>>t2;
				delete_value_2_2(ls,t2);
				cout<<"after delete:\n ";
				print_all(ls);
				break;
			case 10:
				if(delete_min_(ls))
					cout<< "删除成功\n";
				else
					cout<<"删除失败\n";
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

//递归删除ls中的v
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



