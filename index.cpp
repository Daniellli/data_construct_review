#include "index.h"




int main() {

	choose_menu();

	return 0 ;
}



void choose_menu() {
	int user_input,t1,t2,res;
	char tmp;
	user_input=print_menu();
	while(user_input!=0) {
		switch(user_input) {
			case 1:
				initStr(str);
				scanf("%c",&tmp);
				while(tmp!='\0') {
					//û���п�
					str.data[str.length++] = tmp;
					scanf("%c",&tmp);
				}
				str.data[str.length++] = tmp;//�ַ�������
				break;
			case 2:
				printOut(str);
				cout<<"\n";
				break;
		}
		user_input=print_menu();
	}
}



int print_menu() {
	int input;
	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cout<<"��ʼ����������:1 \n";
	cout<<"���������:2 \n";
	cout<<"�˳�������:0 \n";

	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cin>>input;
	return input;
}

/*
Сbug û�д�ȡ�������󳤶�
*/
bool initStr(SString &str,int len) {
	str.data = (char*)malloc(sizeof(char)*len);
	str.length=0;//��ǰ����
	str.max=len;
	
	return true;
}


void printOut(SString str) {
	int i = 0;
	while(str.data[i]!='\0') {
		cout<<str.data[i];
		i++;
	}
}

