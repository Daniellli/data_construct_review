#include"Linear_Stack.h"


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

