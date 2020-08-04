#include"Linear_Stack.h"


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
				break;
			case 2:

				break;
		}
		user_input=print_menu();
	}
}
int main() {
	choose_menu();

	return 0;
}

