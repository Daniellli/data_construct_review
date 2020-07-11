#include"dlinklist.h"


DLinkList dls;


int main(){
	
	
	
	
return 0;	
}


bool init_list() {

dls = (DLinkList)malloc(sizeof(DNode));
dls->prior=dls->next=NULL;
return true;

} 
bool is_empty(DLinkList ls){
	return ls==NULL;
}

bool input_some_value(){
	if(is_empty(dls))
return false;	
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
//			case 2:
//				print_all(ls);
//				break;
//			case 3:
//				cout<<"what is the rank :\n";
//				cin>>t1;
//				print_one(get_Elem(ls,t1));
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
//				insert_value(ls,t1,t2);
//				break;
//			case 6:
//				cout<<"the position you want to delete :\n";
//				cin>>t1;
//				delete_node_by_pos(ls,t1);
//				break;
//			case 7:
//				cout<<size(ls)<<"\n";

		}
		user_input=print_menu();
	}
}




