#include "index.h"




SString str;
int main() {

	choose_menu();

	return 0 ;
}

bool strEmpty(SString s) {
	return s.length==0;
}

int strLength(SString S) {

	return S.length;
}

//pos���û������λ�� ��Ҫ��һ
bool subString(SString &sub,SString S,int pos,int len) {
	int i = pos-1 ;//�����±��0��ʼ
	if(pos+len > strLength(S)) {
		return false;
	}

	while(i<pos+len-1) {
		sub.data[sub.length++] = S.data[i++];
	}

	return true;
}


bool concat(SString &T,SString S1,SString S2) {
	int i ;
	i = 0;

	while(S1.data[i]!='\0') {
		T.data[T.length++] = S1.data[i++];
	}
	i=0;
	while(S2.data[i]!='\0') {
		T.data[T.length++] = S2.data[i++];
	}

	T.data[T.length++] = '\0';

	return true;
}

int strCompare(SString S,SString T) {

	if(strEmpty(S) &&strEmpty(T)) {
		return 0;//��Ϊ��
	} else if(strEmpty(S) ) {
		return -1;//T>S
	} else if(strEmpty(T))
		return 1;//S>T
	//��Ϊ��

	int i ,j;
	i=j=0;
	while(S.data[i] != '\0' && T.data[j]!='\0' &&S.data[i]==T.data[j]) {
		i++;
		j++;
	}
	if(S.data[i] > T.data[j]) {
		return 1;
	} else if(S.data[i] < T.data[j]) {
		return -1;
	} else
		return 0;

}

bool strAssign(SString &T,char *chars) {
	int i=0;
	while(chars[i]!='\0') {
		T.data[T.length++]=chars[i++];
	}
	T.data[T.length++]='\0';
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

	cout<<"\n";
}



void choose_menu() {
	int user_input,t1,t2,res;
	char tmp;
	char * t;
	SString str2,str3;
	user_input=print_menu();
	while(user_input!=0) {
		switch(user_input) {
			case 1:
				t = (char*)malloc(sizeof(char)*MaxLen);
				initStr(str,MaxLen);
				cout<<"�����봮\n";
				getchar();
				gets(t);
				strAssign(str,t);
				free(t);//������  ���ݴ洢����str����  �����ͷ���
//				getchar();
//				scanf("%c",&tmp);
//				while(tmp!='\n') {
//					//û���п�
//					str.data[str.length++] = tmp;
//					scanf("%c",&tmp);
//				}
				//	str.data[str.length++] = '\0';//�ַ�������
				break;
			case 2:
				printOut(str);
				cout<<"\n";
				break;
			case 3:
				initStr(str2,MaxLen);
				t = (char*)malloc(sizeof(char)*MaxLen);
				cout<<"������Ƚϴ�:\n";
				getchar();
				gets(t);
				strAssign(str2,t);
				free(t);
				cout<<strCompare(str,str2)<<"\n";
				free(str2.data);

				//�Ƚ�
				break;
			case 4://substring
				initStr(str2,MaxLen);
				cout<<"pos: ";
				cin>>t1;
				cout<<"len:";
				cin>>t2;
				subString(str2,str,t1,t2);
				printOut(str2);
				free(str2.data);
				break;
			case 5://����
				//concat
				initStr(str2,MaxLen);
				t = (char*)malloc(sizeof(char)*MaxLen);
				cout<<"������ڶ���:\n";
				getchar();
				gets(t);
				strAssign(str2,t);
				free(t);
				//����
				initStr(str3,MaxLen);
				concat(str3,str,str2);
				printOut(str3);
				free(str3.data);
				free(str2.data);

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
	cout<<"�Ƚ�������:3 \n";
	cout<<"���Ӵ�������:4 \n";
	cout<<"����������������:5 \n";
	cout<<"�˳�������:0 \n";

	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cin>>input;
	return input;
}


