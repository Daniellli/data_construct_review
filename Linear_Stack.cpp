#include"Linear_Stack.h"



int main() {
	choose_menu();
	return 0;
}


double caculate() {
	if(fomula.length()==0)return 0;//表达式为空
	char * lastTail ;
	int i=0;
	char n1,n2,res;
	lastTail = transferToLastTail();
	//利用后缀表达式计算
	//只有数字和运算符两种情况
	while(lastTail[i]!='\0') {
		if(lastTail[i]>='0' && lastTail[i]<='9') {
			push(sk,lastTail[i]);
		} else { //运算符
			pop(sk,n2);
			pop(sk,n1);
			//转成可以计算的数字
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
	int i=0,j=0;//i循环变量， j指向结果串
	char tmp;
	char * res = (char*)malloc(sizeof(char)*(fomula.length()+1));
	memset(res,0,sizeof(char)*fomula.length());
	initStack(sk);//初始化栈
	//遍历表达式
	//三种情况 括号  运算符  数字
	while(fomula[i]!='\0') {
		if(fomula[i]>='0' && fomula[i]<='9') {
			res[j++] = fomula[i];
		} else if(fomula[i] == '(' ) { //左括号进栈
			push(sk,fomula[i]);
		} else if(fomula[i] == ')') { //出栈直到左括号
			pop(sk,tmp);//取栈顶 判断是否式左括号
			while(tmp!='(') {
				res[j++] = tmp;//放入结果串
				pop(sk,tmp);//取栈顶 判断是否式左括号
			}
		} else { // 运算符号的情况  直接进栈
			push(sk,fomula[i]);
		}
		i++;
	}

//如果栈非空
	if(!isEmpty(sk)) {
		while(!isEmpty(sk)) {
			pop(sk,tmp);
			res[j++]=tmp;
		}
	}
	res[j] = '\0';//字符串尾
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
	cout<<"输入表达式请输入:1 \n";
	cout<<"输出请输入:2 \n";
	cout<<"计算表达式请输入:3 \n";
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
	int user_input;
	char t1,t2,res;
	string t;
	user_input=print_menu();
	while(user_input!=0) {
		switch(user_input) {
			case 1:
				initStack(sk);
				cout<<"请输入数据\n";
				cin>>fomula;//输入字符串
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
//				cout<<"请输入数据\n";
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


