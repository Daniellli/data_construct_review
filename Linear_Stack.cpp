#include"Linear_Stack.h"



int main() {
	choose_menu();
	return 0;
}


double caculate() {
	if(fomula.length()==0)return 0;//���ʽΪ��
	char * lastTail ;
	int i=0;
	char n1,n2,res;
	lastTail = transferToLastTail();
	//���ú�׺���ʽ����
	//ֻ�����ֺ�������������
	while(lastTail[i]!='\0') {
		if(lastTail[i]>='0' && lastTail[i]<='9') {
			push(sk,lastTail[i]);
		} else { //�����
			pop(sk,n2);
			pop(sk,n1);
			//ת�ɿ��Լ��������
			n1 = n1-'0';
			n2 = n2 - '0';

			switch(lastTail[i]) {
				case '+':
					push(sk,(char)((n1+n2)+'0'));
					break;
				case '-':
					push(sk,(char)((n1-n2)+'0'));
					break;
				case '*':
					push(sk,(char)((n1*n2)+'0'));
					break;
				case '/':
					push(sk,(char)((n1/n2)+'0'));
					break;
			}
		}
		i++;
	}
//	puts(lastTail);
	pop(sk,res);
	return (double)(res-'0');
}

char * transferToLastTail() {
	int i=0,j=0;//iѭ�������� jָ������
	char tmp;
	char * res = (char*)malloc(sizeof(char)*(fomula.length()+1));
	memset(res,0,sizeof(char)*fomula.length());
	initStack(sk);//��ʼ��ջ
	//�������ʽ
	//������� ����  �����  ����
	while(fomula[i]!='\0') {
		if(fomula[i]>='0' && fomula[i]<='9') {
			res[j++] = fomula[i];
		} else if(fomula[i] == '(' ) { //�����Ž�ջ
			push(sk,fomula[i]);
		} else if(fomula[i] == ')') { //��ջֱ��������
			pop(sk,tmp);//ȡջ�� �ж��Ƿ�ʽ������
			while(tmp!='(') {
				res[j++] = tmp;//��������
				pop(sk,tmp);//ȡջ�� �ж��Ƿ�ʽ������
			}
		} else { // ������ŵ����  ֱ�ӽ�ջ
			push(sk,fomula[i]);
		}
		i++;
	}

//���ջ�ǿ�
	if(!isEmpty(sk)) {
		while(!isEmpty(sk)) {
			pop(sk,tmp);
			res[j++]=tmp;
		}
	}
	res[j] = '\0';//�ַ���β
	return res ;
}

bool initStack(LStack &sk) {
	sk.data = (char*)malloc(sizeof(char)*MaxSize);
	sk.top=-1;
	return true;
}

bool push(LStack &sk,ElemType x) {
	if(isFull(sk))return false;

	sk.data[++sk.top]=x;
	return true;
}



bool isFull(LStack sk) {
	return sk.top+1 == MaxSize;

}

bool pop(LStack &sk,ElemType &x) {
	if(isEmpty(sk)) {
		return false;
	}

	x=sk.data[sk.top--] ;

	return true;
}

bool isEmpty(LStack sk) {
	return sk.top==-1;
}


bool getTop(LStack sk,ElemType &x) {
	if(isEmpty(sk))
		return false;
	x=sk.data[sk.top];
	return true;
}

bool printStack(LStack sk) {
	if(isEmpty(sk))
		return false;
	int i;
	for(i =sk.top; i>=0; i--) {
		putchar(sk.data[i]) ;
	}
	cout<<"\n";
	return true;
}
int print_menu() {
	int input;
	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cout<<"������ʽ������:1 \n";
	cout<<"���������:2 \n";
	cout<<"������ʽ������:3 \n";
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
	int user_input;
	char t1,t2,res;
	string t;
	user_input=print_menu();
	while(user_input!=0) {
		switch(user_input) {
			case 1:
				initStack(sk);
				cout<<"����������\n";
				cin>>fomula;//�����ַ���
				break;
			case 2:
				cout<<fomula<<"\n";
//				printStack(sk);
				break;
			case 3:
				//
				cout<<caculate();
				break;
//			case 4:
//				break;
//			case 5:
//				cout<<"����������\n";
//				cin>>t1;
//				push(sk,t1);
//				break;
//			case 6:
//				break;
//			case 7:
//				break;
//			case 8:
//				break;
		}
		user_input=print_menu();
	}
}


