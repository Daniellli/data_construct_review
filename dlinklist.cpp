#include"dlinklist.h"


DLinkList dls;


int main() {
	choose_menu();
	return 0;
}






bool  insert_value(DLinkList ls, int pos,ElemType v) {

	if(is_empty(dls))
		return false;

	if(pos<1 )
		return false;

	DNode  *p = get_Elem(ls,pos);//获取节点
	DNode  *tmp =  (DNode*)malloc(sizeof(DNode));
	tmp->data = v;

	tmp->next= p;
	tmp->prior = p->prior;

	p->prior->next = tmp ;
	p->prior = tmp;


	return true;


}



bool delete_node_by_pos(DLinkList ls, int pos) {

	if(is_empty(ls))return false;

	DNode *p = get_Elem(ls,pos);

	//删除
	p->next->prior = p->prior;
	p->prior->next = p->next;
	free(p);
	return true;
}

bool init_list() {
	dls = (DLinkList)malloc(sizeof(DNode));
	dls->prior=dls->next=dls;
	return true;

}
bool is_empty(DLinkList ls) {
	return ls==NULL;
}

bool input_some_value() {

	if(is_empty(dls))
		return false;
	DNode *t;
	DNode *p = dls;
	ElemType x;
	cout<<"请输入:\n";
	cin>>x;

	while(x!=-1) {
		t = (DNode *)malloc(sizeof(DNode));
		t->data=x;
		if(p->next == p->prior) { //first
			t->next = NULL;
			t->prior = p;
			p->next  = t;
			p=t;
		} else {
//			t->next  = p->next->next;
//			t->prior = p->next;
//			p->next->next = t;
//			p->next=p->next->next;
			t->prior =p;
			t->next = p->next;
			p->next = t;
			p=t;

		}
		cin>>x;
	}
	return true;
}

//bool inserts(DLinkList dls,ElemType x) {
//	if(is_empty(dls))
//		return false;
//
//	DNode *tmp = (DNode *)malloc(sizeof(DNode)),p = dls;

//	tmp->data = x;
//	if(dls->next == dls->prior){//空表插入
//		tmp ->next = NULL;
//		p->next =  tmp;
//		tmp->prior = p;
//	}else{
//		p->next = tmp;
//		tmp->prior = p
//	}
//	tmp.next = p->next;
//	p->next.prior = tmp;
//
//	tmp->prior = p;
//	p->next =s;
//	return true;
//}


DNode* get_Elem(DLinkList dls , int pos) {

	DNode * p = dls;//指向第一个
	int cnt = 0;
	while(!is_empty(p)&& cnt<pos) {
		p = p->next;
		cnt++;
	}
	return p;
}

bool print_all(DLinkList ls) {
	if(ls->next == ls->prior)
		return false;
	DNode *p = ls->prior->next;//指向第一个节点

	while(!is_empty(p)) {
		cout<<p->data<<"\t"	;
		p=p->next;
	}
	cout<<"\n";
	return true;
}


bool print_one(DNode * node) {

	cout<<node->data<<"\n";

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
	cout<<"退出请输入:0 \n";

	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cin>>input;
	return input;
}



void choose_menu() {

	int user_input,t1,t2,res;

	user_input=print_menu();
	while(user_input!=0) {
		switch(user_input) {
			case 1:
				init_list();
				input_some_value();
				break;
			case 2:
				print_all(dls);
				break;
			case 3:
				cout<<"what is the rank :\n";
				cin>>t1;
				print_one(get_Elem(dls,t1));
				break;
//			case 4:
//				cout<<"what is the value :\n";
//				cin>>t2;
//				print_one(get_Elem_by_value(ls,t2));
//				break;
			case 5:
				cout<<"the position you want to insert :\n";
				cin>>t1;
				cout<<"the value you want to insert :\n";
				cin>>t2;
				insert_value(dls,t1,t2);
				break;
			case 6:
				cout<<"the position you want to delete :\n";
				cin>>t1;
				delete_node_by_pos(dls,t1);
				break;
//			case 7:
//				cout<<size(ls)<<"\n";

		}
		user_input=print_menu();
	}
}




