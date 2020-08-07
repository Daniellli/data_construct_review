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
					//没有判空
					str.data[str.length++] = tmp;
					scanf("%c",&tmp);
				}
				str.data[str.length++] = tmp;//字符结束符
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
	cout<<"初始化数据输入:1 \n";
	cout<<"输出请输入:2 \n";
	cout<<"退出请输入:0 \n";

	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cin>>input;
	return input;
}

/*
小bug 没有存取分配的最大长度
*/
bool initStr(SString &str,int len) {
	str.data = (char*)malloc(sizeof(char)*len);
	str.length=0;//当前长度
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

