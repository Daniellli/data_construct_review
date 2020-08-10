#include "biTree.h"

#define ChildNumber 100
SeqBiTree bt;

int main() {

	choose_menu();

	return 0;
}


int find(SeqBiTree bt,int i,int j) {
//	if(i == j)return bt.data[i/2];
//	do {
//		if(i>j) {
//			i/=2;
//		} else if(j>i) {
//			j/=2;
//		}
//	} while(i!=j);

	while(i!=j) {
		if(i>j)
			i/=2;
		else
			j/=2;
	}
	return bt.data[i];

}


//前序遍历
int print_out(SeqBiTree bt,int visit_node) {
	if(bt.childsNumer<=visit_node)return 0;
	else {
		cout<<bt.data[visit_node];//visit()
		print_out(bt,visit_node*2);
		print_out(bt,visit_node*2+1);
	}
	return 1;
}

bool init_tree_data(SeqBiTree &sbt,ElemType * data) {
	int i = 0 ;
	while(data[i]!='\0') {
		if(sbt.childsNumer+1 == sbt.maxNumber) break; //数据结构满了
		sbt.data[sbt.childsNumer++] = data[i++];
	}
	return true;
}

bool init_tree(SeqBiTree &sbt,int max_len) {
	sbt.data = (ElemType*)malloc(sizeof(ElemType)*max_len);
	memset(sbt.data,0,sizeof(ElemType)*max_len);
	sbt.maxNumber = max_len;
	sbt.childsNumer = 1;//从1开始
	return true;
}



int print_menu() {
	int input;
	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cout<<"初始化数据表请输入:1 \n";

	cout<<"退出请输入:0 \n";

	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cin>>input;
	return input;
}


void choose_menu() {

	int user_input,t1,t2,res;
	ElemType *t;
	user_input=print_menu();
	while(user_input!=0) {
		switch(user_input) {
			case 1:
				init_tree(bt,ChildNumber);
				cout<<"请输入初始树的所有节点";
				t = (ElemType*)malloc(sizeof(ElemType)*ChildNumber);
				getchar();
				gets(t);
				//按广度优先的顺序初始化树
				init_tree_data(bt,t);
				free(t);
				break;
			case 2:
				print_out(bt,1);
				break;
			case 3:
				cout<<"input i:";
				cin>>t1;
				cout<<"input j:";
				cin>>t2;
				printf("%c \n",find(bt,t1,t2));
				break;
		}
		user_input=print_menu();
	}
}

