#include"link_list.h"

LinkList ls;



int main() {
	choose_menu();
	return 0;
}


bool init_list() {
	ls = (LinkList)malloc(sizeof(LNode));
	ls->next = ls;
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
	cout<<"�˳�������:0 \n";

	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cin>>input;
	return input;
}




bool input_some_value() {

	cout<<"input :\n";

	ElemType x;
	LNode *t,*p = ls;

	cin>>x;
	while(x!=-1) {
		t=(LNode*) malloc(sizeof(LNode));
		t->data = x;
		t->next= p->next;
		p->next=t;
		p=t;
		cin>>x;
	}



	return true;
}


bool print_all(LinkList ls) {

	LNode *p = ls->next;


	while(p!= ls) {
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<"\n";
	return true;
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
				print_all(ls);
				break;
//			case 3:
//				cout<<"what is the rank :\n";
//				cin>>t1;
//				print_one(get_Elem(dls,t1));
//				break;
//			case 4:
//				cout<<"what is the value :\n";
//				cin>>t2;
//				print_one(get_Elem_by_value(ls,t2));
//				break;
//			case 5:
//				cout<<"the position you want to insert :\n";
//				cin>>t1;
//				cout<<"the value you want to insert :\n";
//				cin>>t2;
//				insert_value(dls,t1,t2);
//				break;
//			case 6:
//				cout<<"the position you want to delete :\n";
//				cin>>t1;
//				delete_node_by_pos(dls,t1);
//				break;
//			case 7:
//				cout<<size(ls)<<"\n";

		}
		user_input=print_menu();
	}
}




